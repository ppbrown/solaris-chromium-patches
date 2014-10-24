diff --git a/base/os_compat_solaris.h b/base/os_compat_solaris.h
new file mode 100644
index 0000000..49a1204
--- /dev/null
+++ b/base/os_compat_solaris.h
@@ -0,0 +1,20 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// This file has been started by just copying os_compat_nacl.h
+// Made a separate file for potential future needs.
+
+#ifndef BASE_OS_COMPAT_SOLARIS_H_
+#define BASE_OS_COMPAT_SOLARIS_H_
+
+
+#include <sys/types.h>
+
+#if !defined (__GLIBC__)
+// like NaCl, Solaris  has no timegm().
+extern "C" time_t timegm(struct tm* const t);
+#endif  // !defined (__GLIBC__)
+
+#endif  // BASE_OS_COMPAT_SOLARIS_H_
+
