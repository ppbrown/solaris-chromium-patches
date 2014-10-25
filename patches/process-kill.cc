diff --git a/base/process/kill.cc b/base/process/kill.cc
index caca348..cae4aeb 100644
--- a/base/process/kill.cc
+++ b/base/process/kill.cc
@@ -11,6 +11,14 @@ namespace base {
 bool KillProcesses(const FilePath::StringType& executable_name,
                    int exit_code,
                    const ProcessFilter* filter) {
+#ifdef OS_SOLARIS
+  // Yes, ugly hack for now. 
+  char cmdstring[1024];
+  sprintf(cmdstring, "pkill %s.1000", executable_name.c_str());
+  system(cmdstring);
+  return 0;
+
+#else
   bool result = true;
   NamedProcessIterator iter(executable_name, filter);
   while (const ProcessEntry* entry = iter.NextProcessEntry()) {
@@ -21,6 +29,7 @@ bool KillProcesses(const FilePath::StringType& executable_name,
 #endif
   }
   return result;
+#endif
 }
 
 }  // namespace base
