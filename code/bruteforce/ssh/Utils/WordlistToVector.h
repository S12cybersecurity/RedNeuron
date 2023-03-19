#include <vector>
#include <iostream> 
#include <fstream>

using namespace std;

vector<string> readPasswordsFromFile(string fileName) {
    vector<string> passwords;
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            passwords.push_back(line);
        }
    }
    else {
        cout << "Error opening file: " << fileName << endl;
    }
    return passwords;
}