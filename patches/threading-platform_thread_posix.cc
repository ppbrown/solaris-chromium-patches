diff --git a/base/threading/platform_thread_posix.cc b/base/threading/platform_thread_posix.cc
index 42b416d..21ba1c6 100644
--- a/base/threading/platform_thread_posix.cc
+++ b/base/threading/platform_thread_posix.cc
@@ -24,6 +24,9 @@
 #if defined(OS_LINUX)
 #include <sys/prctl.h>
 #include <sys/resource.h>
+#endif
+
+#if defined(OS_LINUX) || defined(OS_SOLARIS)
 #include <sys/syscall.h>
 #include <sys/time.h>
 #include <unistd.h>
