#include <mysql.h>
#include <iostream>
#include <string>

//connect to mysql database
class SQL{
    private:
        std::string server;
        std::string user;
        std::string password;
        std::string database;
        MYSQL *conn;

    public:
        SQL(std::string server, std::string user, std::string password, std::string database){
            this->server = server;
            this->user = user;
            this->password = password;
            this->database = database;
        }

        // getters and setters
        std::string getServer(){
            return server;
        }
        void setServer(std::string server){
            this->server = server;
        }
        std::string getUser(){
            return user;
        }
        void setUser(std::string user){
            this->user = user;
        }
        std::string getPassword(){
            return password;
        }
        void setPassword(std::string password){
            this->password = password;
        }
        std::string getDatabase(){
            return database;
        }
        void setDatabase(std::string database){
            this->database = database;
        }

        bool connect(){
            //CONNECTION TO MYSQL DATABASE
            MYSQL_RES *res;
            MYSQL_ROW row;
            conn = mysql_init(nullptr);
            if(!mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), database.c_str(), 0, nullptr, 0)){
                return false;
            }
            else{
                return true;
            }
        }
};
