#include <iostream>
#include <cctype>
#include "create.h"

using namespace std;

string op;
int cont;

void createshell(){
    string op;
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
        else if(op == "a"){
            //hahah
        }
        else if (op == "help" || op == "Help" || op == "HELP"){
            createmenu();
        }
        else if (op == "reverse shell"){
            createrevshell();
        }
        else if (op == "revshell" || op == "Revshell" || op == "REVSHELL"){
            createrevshell();
        }
        else if (op == "clear" || op == "Clear" || op == "CLEAR"){
            system("clear");
        }
        else if (op == "commands" || op == "Commands" || op == "COMMANDS"){
            createcommands();
        }
        else if (op == "main" || op == "Main" || op == "MAIN"){
            //soon...
        }
        else if (op == "persistence" || op == "Persistence" || op == "PERSISTENCE"){
            createpersistence();
        }
        else if (op == "proclist" || op == "Proclist" || op == "PROCLIST"){
            createproclist();
        }        
        else if(op == "windowinjector" || op == "Windowinjector" || op == "WINDOWINJECTOR"){
            createWindowInjector();
        }
        else{
            if (cont != 0){
                red("\n[-] Command not found\n");
            }
        }
        cont++;
    }
}

static int postexploitationshell(){
    op = "a";
    while (op != "exit" && op != "Exit" && op != "EXIT"){
        cout<<"\nRedNeuron@postexploitation-> ";
        cin>>op;
        if (op == "help" || op == "Help" || op == "HELP"){
            postexploitationmenu();
        }
        else if (op == "clear" || op == "Clear" || op == "CLEAR"){
            system("clear");
        }
        else if (op == "list" || op == "List" || op == "LIST"){
           // postexploitationlist();
        }
        else if (op == "commands" || op == "Commands" || op == "COMMANDS"){
         //   postexploitationlist();
        }
        else if (op == "file-extractor" || op == "File-extractor" || op == "FILE-EXTRACTOR"){
            system("./code/postexploitation/file-extractor/file-extractor.sh");
        }
        else if (op == "mysql-stealer" || op == "Mysql-stealer" || op=="MYSQL-STEALER"){
            system("./code/postexploitation/MySQL-dataStealer/MySQL_DataStealer.sh");
        }
        else if (op == "main" || op == "Main" || op == "MAIN"){
            //soon...
        }
        else if (op == "main" || op == "Main" || op == "MAIN"){
            //soon...
        }
        else{
            red("\n[-] Command not found\n");
        }
    }
    return 0;
}

static int bruteforceshell(){
    op = "a";
    while (op != "exit" && op != "Exit" && op != "EXIT"){
        cout<<"\nRedNeuron@bruteforce-> ";
        cin>>op;
        if (op == "ssh" || op == "Ssh" || op == "SSH"){
            system("./code/bruteforce/ssh/bruteSSH");
        }
        else if(op == "help" || op == "Help" || op == "HELP" || op == "commands" || op == "Commands" || op == "COMMANDS"){
            bruteforcemenu();
        }
        else if(op == "mysql" || op == "Mysql" || op == "MYSQL"){
            system("./code/bruteforce/mysql/bruteMySQL");
        }
        else if (op == "list" || op == "List" || op == "LIST"){
            bruteforcelist();
        }
        else if (op == "clear" || op == "Clear" || op == "CLEAR"){
            system("clear");    
        }
    }
    return 0;
}

static int mainshell(){
    op = "a";
    while (op != "exit" && op != "Exit" && op != "EXIT" ){
        cout<<"\nRedNeuron@main-> ";
        cin>>op;
        if (op == "create" || op == "Create" || op == "CREATE"){
            createshell();
        }
        else if (op == "create help" || op == "Create Help" || op == "CREATE HELP"){
            //createmenu();
        }
        else if (op == "create list" || op == "Create List" || op == "CREATE LIST"){
            listcreate();
        }
        else if (op == "create revshell" || op == "Create Revshell" || op == "CREATE REVSHELL"){
            createrevshell();
        }
        else if (op == "clear" || op == "Clear" || op == "CLEAR"){
            system("clear");
        }
        else if (op == "help" || op == "Help" || op == "HELP"){
            helpmenu();
        }
        else if (op == "list" || op == "List" || op == "LIST"){
            commandsmenu();
        }
        else if (op == "commands" || op == "Commands" || op == "COMMANDS"){
            commandsmenu();
        }
        else if (op == "bruteforce" || op == "Bruteforce" || op == "BRUTEFORCE"){
            bruteforcemenu();
            bruteforceshell();
        }
        else if (op == "create reverse shell" || op == "Create Reverse Shell" || op == "CREATE REVERSE SHELL"){
            createrevshell();
        }
        else if (op == "postexploitation" || op == "Postexploitation" || op == "POSTEXPLOITATION"){
            postexploitationmenu();
            postexploitationshell();
        }       
        else{
            red("\n[-] Command not found\n");
        }
    }
    green("\nBye Bye :)");

    return 0;
}