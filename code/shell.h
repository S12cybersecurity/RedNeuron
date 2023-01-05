#include <iostream>
#include <cctype>
#include "create.h"

using namespace std;

string op;
int cont;

void createshell(){
    op = "";
    cont = 0;
    createmenu(); 
    while (op != "exit" && op != "Exit" && op != "EXIT" )
    {
        if (cont != 0) {
            cout<<"\nRedNeuron@create-> ";
        }
        getline(cin, op);    
        if (op == "list" || op == "List" || op == "LIST"){
            listcreate();
        }
        if (op == "help" || op == "Help" || op == "HELP"){
            createmenu();
        }
        if (op == "reverse shell"){
            createrevshell();
        }
        if (op == "revshell" || op == "Revshell" || op == "REVSHELL"){
            createrevshell();
        }
        if (op == "clear" || op == "Clear" || op == "CLEAR"){
            system("clear");
        }
        if (op == "commands" || op == "Commands" || op == "COMMANDS"){
            createcommands();
        }
        if (op == "main" || op == "Main" || op == "MAIN"){
            //soon...
        }
        cont++;
    }
}

static int mainshell(){
    op = "a";
    while (op != "exit" && op != "Exit" && op != "EXIT" ){
        cout<<"\nRedNeuron@main-> ";
        cin>>op;
        if (op == "create" || op == "Create" || op == "CREATE"){
            createshell();
        }
        if (op == "create help" || op == "Create Help" || op == "CREATE HELP"){
            //createmenu();
        }
        if (op == "create list" || op == "Create List" || op == "CREATE LIST"){
            listcreate();
        }
        if (op == "create revshell" || op == "Create Revshell" || op == "CREATE REVSHELL"){
            createrevshell();
        }
        if (op == "clear" || op == "Clear" || op == "CLEAR"){
            system("clear");
        }
        if (op == "help" || op == "Help" || op == "HELP"){
            helpmenu();
        }
        if (op == "list" || op == "List" || op == "LIST"){
            commandsmenu();
        }
        if (op == "commands" || op == "Commands" || op == "COMMANDS"){
            commandsmenu();
        }
        if (op == "create reverse shell" || op == "Create Reverse Shell" || op == "CREATE REVERSE SHELL"){
            createrevshell();
        }       
    }
    green("\nBye Bye :)");

    return 0;
}