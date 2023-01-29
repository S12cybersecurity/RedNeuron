#include <iostream>
#include <string>
#include <libssh/libssh.h>
#include "Utils/ColorClass.h"


using namespace std;

class SSHHost{
    public:
        string ip;
        string user;

        SSHHost(string ip,string user){
            this->ip = ip;
            this->user = user;
        }

        ssh_session SSHConnection(string ip, string user){

            ssh_session session = ssh_new();
            ssh_options_set(session, SSH_OPTIONS_HOST, ip.c_str());

            int rc = ssh_connect(session);
            if (rc != SSH_OK){
                red("\nServer connection unsuccesfull\n");
                cout<<"Error: "<<ssh_get_error(session) << endl;
            }
            else if(rc == 0){
                return session;
            }
        }

        int SSHAuth(ssh_session session,string user,string password){
            // Authentication
            int rc;
            rc = ssh_userauth_password(session, user.c_str(), password.c_str());
            if (rc != SSH_AUTH_SUCCESS){
            }
            else if (rc ==  SSH_AUTH_SUCCESS) {
                green("Password Found: ");
                cout<<password<<"\n";
            }
            return rc;
        }
    
};  