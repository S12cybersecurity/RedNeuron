#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"


ENDCOLOR="\e[0m"



printf "${CYAN}\nPATH to save EXE = ${ENDCOLOR}"
read -r exepath
x86_64-w64-mingw32-g++ code/persistence/runkeys2.cpp -I/usr/share/mingw-w64/include/  -o $exepath/runkeys.exe -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -fpermissive -Wmain

ls $exepath/runkeys.exe >/dev/null
e=$(echo $?)

if [ $e == 0 ]; then
	echo -e "${GREEN}\n[+] File Created Successfully - runkeys.exe${ENDCOLOR}"
else
	echo -e "${RED}[-] Error Creating File${ENDCOLOR}\n"
        exit
fi