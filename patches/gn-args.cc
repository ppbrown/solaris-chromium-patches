diff --git a/tools/gn/args.cc b/tools/gn/args.cc
index bce1ad2..a8fb7ae 100644
--- a/tools/gn/args.cc
+++ b/tools/gn/args.cc
@@ -221,6 +221,8 @@ void Args::SetSystemVarsLocked(Scope* dest) const {
   os = "linux";
 #elif defined(OS_ANDROID)
   os = "android";
+#elif defined(OS_SOLARIS)
+  os = "solaris";
 #else
   #error Unknown OS type.
 #endif
