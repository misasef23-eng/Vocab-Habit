/* Service worker của VocabHabit: giúp mở được app khi không có mạng.
   - Trang chính: ưu tiên bản mới từ mạng (để người dùng luôn nhận bản cập nhật), mất mạng hoặc mạng chậm thì dùng bản đã lưu.
   - Ảnh icon, manifest: dùng bản đã lưu trước.
   Mỗi lần đổi icon hoặc danh sách file cần lưu sẵn, hãy tăng VERSION để trình duyệt tải lại bộ lưu sẵn. */
const VERSION = 'v2';
const CACHE = 'vocabhabit-' + VERSION;
const PRECACHE = [
  './',
  'manifest.webmanifest',
  'favicon.ico',
  'favicon.svg',
  'icons/icon-192.png',
  'icons/icon-512.png',
  'icons/icon-maskable-512.png',
  'icons/apple-touch-icon.png'
];

self.addEventListener('install', (e) => {
  e.waitUntil(caches.open(CACHE).then((c) => c.addAll(PRECACHE)).then(() => self.skipWaiting()));
});

self.addEventListener('activate', (e) => {
  e.waitUntil(
    caches.keys()
      .then((keys) => Promise.all(keys.filter((k) => k.startsWith('vocabhabit-') && k !== CACHE).map((k) => caches.delete(k))))
      .then(() => self.clients.claim())
  );
});

self.addEventListener('fetch', (e) => {
  const req = e.request;
  if (req.method !== 'GET') return;
  const url = new URL(req.url);
  if (url.origin !== self.location.origin) return;          // không can thiệp yêu cầu tới trang khác
  if (req.mode === 'navigate') {
    e.respondWith(networkFirst(req));
  } else {
    e.respondWith(cacheFirst(req));
  }
});

function fetchWithTimeout(req, ms) {
  if (!ms) return fetch(req);
  const ctl = new AbortController();
  const t = setTimeout(() => ctl.abort(), ms);
  return fetch(req, { signal: ctl.signal }).finally(() => clearTimeout(t));
}

async function networkFirst(req) {
  const cache = await caches.open(CACHE);
  const cached = await cache.match('./');
  try {
    // đã có bản lưu sẵn thì chỉ chờ mạng tối đa 4 giây, lần đầu chưa có gì thì chờ bao lâu cũng được
    const net = await fetchWithTimeout(req, cached ? 4000 : 0);
    if (net && net.ok && !net.redirected) cache.put('./', net.clone());
    return net;
  } catch (err) {
    if (cached) return cached;
    throw err;
  }
}

async function cacheFirst(req) {
  const cache = await caches.open(CACHE);
  const hit = await cache.match(req);
  if (hit) return hit;
  const net = await fetch(req);
  if (net && net.ok && net.type === 'basic') cache.put(req, net.clone());
  return net;
}
