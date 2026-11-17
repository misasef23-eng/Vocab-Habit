/* Service Worker mẫu cho cấu trúc nhiều file.
   CHỈ dùng nếu bạn chưa có sw.js riêng: đổi tên file này thành sw.js.
   Nếu đã có sw.js: chỉ cần thêm các đường dẫn trong danh sách FILES bên dưới vào danh sách cache của bạn,
   và đổi tên phiên bản cache (VERSION) để người dùng cũ nhận bản mới. */
var VERSION = "vocabhabit-v2";
var FILES = [
  "./", "index.html",
  "data/ipa.js", "data/endict.js", "data/decks.js",
  "fonts/lato-400.woff2", "fonts/lato-600-700.woff2",
  "manifest.webmanifest", "favicon.ico", "icons/apple-touch-icon.png"
];
self.addEventListener("install", function (e) {
  /* Từng file một: thiếu file nào (ví dụ icon) cũng không làm hỏng cả lần cài. */
  e.waitUntil(caches.open(VERSION).then(function (c) {
    return Promise.all(FILES.map(function (f) { return c.add(f).catch(function () {}); }));
  }).then(function () { return self.skipWaiting(); }));
});
self.addEventListener("activate", function (e) {
  e.waitUntil(caches.keys().then(function (ks) {
    return Promise.all(ks.filter(function (k) { return k !== VERSION; }).map(function (k) { return caches.delete(k); }));
  }).then(function () { return self.clients.claim(); }));
});
self.addEventListener("fetch", function (e) {
  if (e.request.method !== "GET") return;
  e.respondWith(caches.match(e.request, { ignoreSearch: true }).then(function (hit) {
    return hit || fetch(e.request).then(function (res) {
      var copy = res.clone();
      if (res.ok && new URL(e.request.url).origin === location.origin)
        caches.open(VERSION).then(function (c) { c.put(e.request, copy); });
      return res;
    });
  }));
});
