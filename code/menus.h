#include <iostream>
#include "ColorClass.h"

using namespace std;

int mainmenu() {
    yellow("\t         RedNeuron\n");
    yellow("\t    Author S12 -> salsa");
    yellow("\n\t         Version 1.1");
    return 0;
}

void helpmenu(){
    cyan("\nHELP MENU\n");
    red("Disclaimer: Im not responsable of the use for this tool\n");
    cyan("\nDeveloped with: C++ - Python - Bash\nVersion 1.1\n\nGithub: https://github.com/S12cybersecurity/RedNeuron\nMedium: https://medium.com/@s12deff\n\nCommands:\n- help -> List this Menu\n- list -> List avaible commands\n- commands -> List avaible commands\n- create -> Section to Create avaible Malware\n- clear -> Clear actual screen\n");
}

void commandsmenu(){
    cyan("\nCommands:\n- help -> List this Menu\n- list -> List avaible commands\n- commands -> List avaible commands\n- create -> Section to Create avaible Malware\n- clear -> Clear actual screen\n");
}


void createmenu() {
    cyan("\nHelp Menu for Create\nIn this moment tho only allowed \nCreate Module in RedNeuron allow you to use this commands:\n- help\n- list\n- reverse shell\n- revshell\n");
}

void listcreate(){
    cyan("\nYou can create this malware options:\n- Reverse Shell to Bypass Windows Defender\n");
}

bool checkdependeces(){
    system("bash code/checks.sh");
    return true;
}
