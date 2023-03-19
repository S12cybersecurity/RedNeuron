#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
ENDCOLOR="\e[0m"

                        
compiler_exists() {
    if which x86_64-w64-mingw32-g++ >/dev/null; then
        echo true
    else
        echo false
    fi
}

payload_creator_exists() {
    if which msfvenom >/dev/null; then
        echo true
    else
        echo false
    fi
}

echo -e "${YELLOW}[+] Checking Dependencies...${ENDCOLOR}\n"

if [ "$(compiler_exists)" == true ] && [ "$(payload_creator_exists)" == true ]; then
    echo -e "${GREEN}[+] Dependencies Found ${ENDCOLOR}"
    sleep 3s
    clear
else
    echo -e "${RED}[-] Some Dependencies not Found${ENDCOLOR}"
    if [ "$(compiler_exists)" == false ]; then
        echo -e "You can install the compiler with: sudo apt-get install g++-mingw-w64"
    fi
    if [ "$(payload_creator_exists)" == false ]; then
        echo -e "You can install the payload creator following this guide: https://adamtheautomator.com/install-metasploit-on-ubuntu/"
    fi
    exit
fi


echo -e "${RED}                                                                
 _ _ _ _       _              _____       _         _           
| | | |_|___ _| |___ _ _ _   |     |___  |_|___ ___| |_ ___ ___ 
| | | | |   | . | . | | | |  |-   -|   | | | -_|  _|  _| . |  _|
|_____|_|_|_|___|___|_____|  |_____|_|_|_| |___|___|_| |___|_|  
                                       |___|                    ${ENDCOLOR}\n"

echo -e "${RED}\t\t  Created by S12 <-> Salsa${ENDCOLOR}"

bash code/WindowInjector/src/shellcodegen.sh
