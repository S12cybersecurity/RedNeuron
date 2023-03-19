#include <iostream>
#include <string.h>

using namespace std;

void red(string text)
{
    cout << "\033[31m" << text   << "\033[0m";
}
void blue(string text)
{
    cout << "\033[34m" << text << "\033[0m";
}
void yellow(string text)
{
    cout << "\033[33m" << text << "\033[0m";
}
void black(string text)
{
    cout << "\033[30m" << text << "\033[0m";
}
void green(string text)
{
    cout << "\033[32m" << text << "\033[0m";
}
void cyan(string text)
{
    cout << "\033[36m" << text << "\033[0m";
}
