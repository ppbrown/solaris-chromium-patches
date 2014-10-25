diff --git a/base/process/kill_posix.cc b/base/process/kill_posix.cc
index bff7be4..544b9a3 100644
--- a/base/process/kill_posix.cc
+++ b/base/process/kill_posix.cc
@@ -248,6 +248,17 @@ bool WaitForExitCodeWithTimeout(ProcessHandle handle,
 bool WaitForProcessesToExit(const FilePath::StringType& executable_name,
                             base::TimeDelta wait,
                             const ProcessFilter* filter) {
+#if defined(OS_SOLARIS)
+  // Okay, yes this is an ugly hack. But filling out all the
+  // process_iterator_BLAHBLAHBLAH garbage is even uglier, and
+  // the only purpose is to wait around for a named process to die.
+  // We dont need things that fancy. Just fake it for now,
+  // presume it will die eventually :)
+  
+    base::PlatformThread::Sleep(base::TimeDelta::FromMilliseconds(400));
+    return 0;
+
+#else
   bool result = false;
 
   // TODO(port): This is inefficient, but works if there are multiple procs.
@@ -264,6 +275,7 @@ bool WaitForProcessesToExit(const FilePath::StringType& executable_name,
   } while ((end_time - base::TimeTicks::Now()) > base::TimeDelta());
 
   return result;
+#endif
 }
 
 #if defined(OS_MACOSX)
