#include <iostream>
#include "code/menus.h"
#include "code/shell.h"

using namespace std;

int main() {
    checkdependeces();
    system("bash code/banner.sh");
    mainmenu();
    cout<<"\n\n";
    helpmenu();
    mainshell();
    return 0;
}

