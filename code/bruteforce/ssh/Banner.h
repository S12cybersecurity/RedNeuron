#include <iostream>
#include <string>

using namespace std;

int banner(){
    cout << "\033[1;31m"; //Este código ANSI cambia el color del texto a rojo
    string border(35, '*');
    cout << border << endl;
    string text = "BruteSSH";
    int center = (35 - text.length()) / 2;
    cout << "" << string(center, ' ') << text << string(center, ' ') << "" << endl;
    cout << border << endl;
    cout << "\033[0m"; //Este código ANSI vuelve al color de texto predeterminado
    return 0;
}
