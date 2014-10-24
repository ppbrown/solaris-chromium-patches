diff --git a/tools/gn/settings.h b/tools/gn/settings.h
index e66a13f..0dfaacb 100644
--- a/tools/gn/settings.h
+++ b/tools/gn/settings.h
@@ -30,7 +30,8 @@ class Settings {
     UNKNOWN,
     LINUX,
     MAC,
-    WIN
+    WIN,
+    SOLARIS
   };
 
   // Constructs a toolchain settings.
