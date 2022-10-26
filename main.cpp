#include <iostream>
#include <string>
#include <fstream>
// including file stream to get info to and from the disk and the program

using namespace std;
// using the standard library for naming

class loginZeus{
    // public keyword, meaning anyone can access
    public:
        loginZeus(){
            authenticate = false;
        };
    void login(){
        // cout is a response in console
        cout << "please enter your almighty name /nUsername:";
        // cin is input from user
        cin >> usernameMatch;

        // retreaving the username from a file
        username = getFile("users.txt");

        if(usernameMatch == username){
            cout << "please enter the almighty password:";
            cin >> passwordMatch;

            password = getFile("password.txt");

            if(passwordMatch == password) {
                cout << "correct password";
                cin.get();
            }
            else {
                cout << "wrong password";
                login();
            }
        }
        else {
            cout << "wrong username";
            login();
        }
    }

    // define a function to retrieve the password and usernames from a stored file
    string getFile(const char* p_file)
        {
            string line;
            fstream file;

            file.open(p_file, ios::in);
            if(file.is_open())
                {
                    getline(file, line);
                }
            file.close();

            return line;
        }

    // only Zeus can access the following
     private:
        string password;
        string username;
        string usernameMatch;
        string passwordMatch;
        bool authenticate;
        
};

int main(){
    loginZeus loginZuesObject;
    loginZuesObject.login();

    cin.get();
}