diff --git a/tools/gn/settings.cc b/tools/gn/settings.cc
index a5f90d6..5a98121 100644
--- a/tools/gn/settings.cc
+++ b/tools/gn/settings.cc
@@ -40,6 +40,8 @@ Settings::Settings(const BuildSettings* build_settings,
   // Currently we don't have an "Android" target OS, it looks just like Linux
   // from our perspective.
   target_os_ = LINUX;
+#elif defined(OS_SOLARIS)
+  target_os_ = SOLARIS;
 #else
   #error implement me
 #endif
