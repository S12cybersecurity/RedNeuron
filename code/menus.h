#include <iostream>
#include "ColorClass.h"

using namespace std;

int mainmenu() {
    yellow("\t         RedNeuron\n");
    yellow("\t    Author S12 -> salsa");
    yellow("\n\t         Version 1.2 ");
    return 0;
}

void helpmenu(){
    cyan("\nHELP MENU\n");
    red("Disclaimer: Im not responsable of the use for this tool\n");
    cyan("\nDeveloped with: C++ - Python - Bash\nVersion 1.2\n\nGithub: https://github.com/S12cybersecurity/RedNeuron\nMedium: https://medium.com/@s12deff\n\nCommands:\n- help -> List this Menu\n- list -> List available commands\n- commands -> List available commands\n- create -> Section to Create available Malware\n- clear -> Clear actual screen\n");
}

void commandsmenu(){
    cyan("\nCommands:\n- help -> List this Menu\n- list -> List available commands\n- commands -> List available commands\n- create -> Section to Create available Malware\n- clear -> Clear actual screen\n");
}

void createcommands(){
    cyan("\nShell Commands:\n- help -> Show Help Menu\n- list -> List all malware available \n- commands -> List available commands\n- clear -> Clear actual screen\n\nMalware Commands:\n- reverse shell -> Create Undetectable Windows Reverse Shell\n- revshell -> Create Undetectable Windows Reverse Shell\n- persistence -> Create EXE to get Persistence in Windows Victim\n");
}

void createmenu() {
    cyan("\nHelp Menu for Create\nIf you want to see all malware available execute 'list' command \n\nCreate Section in RedNeuron allow you to use this commands:\n\nShell Commands:\n- help -> Show Help Menu\n- list -> List all malware available \n- commands -> List available commands\n- clear -> Clear actual screen\n\nMalware Commands:\n- reverse shell -> Create Undetectable Windows Reverse Shell\n- revshell -> Create Undetectable Windows Reverse Shell\n- persistence -> Create EXE to get Persistence in Windows Victim\n");
}

void listcreate(){
    cyan("\nYou can create this malware options:\n- Reverse Shell to Bypass Windows Defender (Command 'revshell' or 'reverse shell')\n- EXE to get Persistence in Windows Victim (Command 'persistence')\n");
}

bool checkdependeces(){
    system("bash code/checks.sh");
    return true;
}
