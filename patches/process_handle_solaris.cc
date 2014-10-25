diff --git a/base/process/process_handle_solaris.cc b/base/process/process_handle_solaris.cc
new file mode 100644
index 0000000..77c0eef
--- /dev/null
+++ b/base/process/process_handle_solaris.cc
@@ -0,0 +1,58 @@
+// Copyright (c) 2013 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+
+// Note: everywhere else, we are expected to use 64bit offset.
+// But HERE.. we need to use procfs.
+// Which, apparently, is 32bit only!
+// An ifdef bombs out, in sys/procfs.h, unless we undefine this
+// It should be okay so long as the only fd stuff we do in here, is for procfs
+#undef _FILE_OFFSET_BITS
+
+#include "base/process/process_handle.h"
+
+#include "base/files/file_util.h"
+#include "base/strings/string_number_conversions.h"
+
+
+#define _STRUCTURED_PROC 1
+#include <sys/procfs.h>
+
+#include <fcntl.h>
+
+namespace base {
+
+  // This only seems used by WaitForSingleProcess, to determine
+  // if we can wait() for it or not ...
+ProcessId GetParentProcessId(ProcessHandle process) {
+  char path[1024];
+  pstatus_t pstat;
+
+  sprintf(path, "/proc/%d/status", process);
+  
+  int fd = open(path, O_RDONLY);
+  if(fd==-1){
+    return -1;
+  }
+  read(fd, &pstat, sizeof(pstatus_t));
+
+  if (pstat.pr_ppid)
+    return pstat.pr_ppid;
+  return -1;
+}
+
+FilePath GetProcessExecutablePath(ProcessHandle process) {
+  FilePath stat_file = FilePath("/proc");
+  stat_file.Append(IntToString(process));
+  stat_file.Append("path/a.out");
+
+  FilePath exe_name;
+  if (!ReadSymbolicLink(stat_file, &exe_name)) {
+    // No such process.  Happens frequently in e.g. TerminateAllChromeProcesses
+    return FilePath();
+  }
+  return exe_name;
+}
+
+}  // namespace base
