#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
ENDCOLOR="\e[0m"

printf "\nPATH to save EXE = "
read -r shellpath

cp code/proclist/procList.exe $shellpath

ls $shellpath/procList.exe >/dev/null
e=$(echo $?)

if [ $e == 0 ]; then
	echo -e "${GREEN}\n[+] EXE Created Successfully - $shellpath/procList.exe${ENDCOLOR}"
else
	echo -e "${RED}\n[-] Error Creating EXE${ENDCOLOR}\n"
    exit
fi

