diff --git a/base/files/file_posix.cc b/base/files/file_posix.cc
index 43684b5..7385867 100644
--- a/base/files/file_posix.cc
+++ b/base/files/file_posix.cc
@@ -18,6 +18,8 @@
 
 #if defined(OS_ANDROID)
 #include "base/os_compat_android.h"
+#elif defined(OS_SOLARIS)
+#include "base/os_compat_solaris.h"
 #endif
 
 namespace base {
@@ -34,7 +36,7 @@ static int CallFstat(int fd, stat_wrapper_t *sb) {
   base::ThreadRestrictions::AssertIOAllowed();
   return fstat(fd, sb);
 }
-#else
+#else  // OS_SOLARIS wants fstat64 as well
 static int CallFstat(int fd, stat_wrapper_t *sb) {
   base::ThreadRestrictions::AssertIOAllowed();
   return fstat64(fd, sb);
@@ -120,7 +122,7 @@ void File::Info::FromStat(const stat_wrapper_t& stat_info) {
   is_symbolic_link = S_ISLNK(stat_info.st_mode);
   size = stat_info.st_size;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_SOLARIS)
   time_t last_modified_sec = stat_info.st_mtim.tv_sec;
   int64 last_modified_nsec = stat_info.st_mtim.tv_nsec;
   time_t last_accessed_sec = stat_info.st_atim.tv_sec;
