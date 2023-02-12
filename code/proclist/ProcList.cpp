#include <windows.h>
#include "conio.h"
#include <tchar.h>
#include <conio.h>
#include <psapi.h>
#include <iostream>
#include <vector>
#include <tlhelp32.h>
#include <sstream>
#include <lmcons.h> 
#include "ColorClass.h"

void PrintProcessNameAndID(DWORD processID) {
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

    // Get the process name.
    if (NULL != hProcess) {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
            GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
        }
    }

    // Get the parent process ID
    DWORD parentProcessID = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(hSnapshot, &pe32)) {
            do {
                if (pe32.th32ProcessID == processID) {
                    parentProcessID = pe32.th32ParentProcessID;
                    break;
                }
            } while (Process32Next(hSnapshot, &pe32));
        }
        CloseHandle(hSnapshot);
    }

    // Get the username of the process owner
    HANDLE hToken;
    if (OpenProcessToken(hProcess, TOKEN_QUERY, &hToken)) {
        DWORD cbTokenUser = 0;
        GetTokenInformation(hToken, TokenUser, NULL, 0, &cbTokenUser);
        std::vector<char> userInfo(cbTokenUser);
        if (GetTokenInformation(hToken, TokenUser, userInfo.data(), cbTokenUser, &cbTokenUser)) {
            SID_NAME_USE SidType;
            TCHAR lpName[UNLEN + 1];
            DWORD cchName = UNLEN + 1;
            TCHAR lpReferencedDomainName[UNLEN + 1];
            DWORD cchReferencedDomainName = UNLEN + 1;
            if (LookupAccountSid(NULL, reinterpret_cast<TOKEN_USER*>(userInfo.data())->User.Sid, lpName, &cchName, lpReferencedDomainName, &cchReferencedDomainName, &SidType)) {
                printf("Process name: ");
                std::wcout << szProcessName << std::endl;
                printf("Process ID: ");
                std::wcout << processID << std::endl;
                printf("Parent Process ID: ");
                std::wcout << parentProcessID << std::endl;
                printf("User name: ");
                std::wcout << lpName << std::endl;
            CloseHandle(hProcess);
            CloseHandle(hToken);
        }
        }
    }
}
int main() {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    // Get the list of process identifiers.
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        return 1;
    }

    // Calculate how many process identifiers were returned.
    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.
    for (i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
            PrintProcessNameAndID(aProcesses[i]);
            std::cout << std::endl;
        }
    }

    getch();
    return 0;
}
