diff --git a/base/time/time_posix.cc b/base/time/time_posix.cc
index ad00c51..b146674 100644
--- a/base/time/time_posix.cc
+++ b/base/time/time_posix.cc
@@ -24,6 +24,8 @@
 #include "base/os_compat_android.h"
 #elif defined(OS_NACL)
 #include "base/os_compat_nacl.h"
+#elif defined(OS_SOLARIS)
+#include "base/os_compat_solaris.h"
 #endif
 
 #if !defined(OS_MACOSX)
