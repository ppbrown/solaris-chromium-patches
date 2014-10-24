diff --git a/base/os_compat_solaris.cc b/base/os_compat_solaris.cc
new file mode 100644
index 0000000..408caab
--- /dev/null
+++ b/base/os_compat_solaris.cc
@@ -0,0 +1,37 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+
+#include <stdlib.h>
+#include <time.h>
+
+
+extern "C" {
+// There is no futimes() avaiable , so we provide our own..
+// ideally. Except that we need the pathname to use futimesat, and
+// that's more code than i want to deal with right now
+
+int futimes(int fd, const struct timeval tv[2]) {
+  return -1;
+  //return futimesat(fd, NULL, tv);
+}
+
+  // borrowed from os_compat_nacl.cc
+time_t timegm(struct tm* tm) {
+  time_t ret;
+  char* tz;
+  tz = getenv("TZ");
+  setenv("TZ", "", 1);
+  tzset();
+  ret = mktime(tm);
+  if (tz)
+    setenv("TZ", tz, 1);
+  else
+    unsetenv("TZ");
+  tzset();
+  return ret;
+}
+
+
+}  // extern "C"
