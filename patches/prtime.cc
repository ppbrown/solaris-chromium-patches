diff --git a/base/third_party/nspr/prtime.cc b/base/third_party/nspr/prtime.cc
index 9335b01..b2e220e 100644
--- a/base/third_party/nspr/prtime.cc
+++ b/base/third_party/nspr/prtime.cc
@@ -78,6 +78,8 @@
 #include "base/os_compat_android.h"  // For timegm()
 #elif defined(OS_NACL)
 #include "base/os_compat_nacl.h"  // For timegm()
+#elif defined(OS_SOLARIS)
+#include "base/os_compat_solaris.h"  // For timegm()
 #endif
 #include <errno.h>  /* for EINVAL */
 #include <time.h>
