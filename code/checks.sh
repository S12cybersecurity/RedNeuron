#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
ENDCOLOR="\e[0m"

echo -e "${YELLOW}[+] Checking Dependencies...${ENDCOLOR}\n"

which x86_64-w64-mingw32-g++ >/dev/null
a=$(echo $?)


if [ $a == 0 ]; then
    echo -e "${GREEN}[+] Compiler Found ${ENDCOLOR}"
else
    echo -e "${RED}[-] Compiler not Found${ENDCOLOR}"
    echo -e "You can install with: sudo apt-get install g++-mingw-w64"
    exit
fi

which msfvenom >/dev/null
b=$(echo $?)

if [ $b == 0 ]; then
    echo -e "${GREEN}[+] Payload Creator Found ${ENDCOLOR}"
else
    echo -e "${RED}[-] Payload Creator not Found${ENDCOLOR}"
    echo -e "You can install following this guide: https://adamtheautomator.com/install-metasploit-on-ubuntu/"
    exit
fi

which python2 >/dev/null
c=$(echo $?)

if [ $c == 0 ]; then
    echo -e "${GREEN}[+] Python2 Found ${ENDCOLOR}"
else
    echo -e "${RED}[-] Python2 not Found${ENDCOLOR}"
    exit
fi

sleep 3s
clear

