#include <iostream>
#include <string>
using namespace std;
// using the standard library for naming

class loginZeus{
    // public keyword, meaning anyone can access
    public:
        string usernameMatch;
        string passwordMatch;
        loginZeus(){
            authenticate = false;
        };
    void login(){
        // cout is a response in console
        cout << "please enter your almighty name /nUsername:";
        // cin is input from user
        cin >> usernameMatch;
        if(usernameMatch == username){
            cout << "please enter the almighty password:";
            cin >> passwordMatch;
            if(passwordMatch == password) {
                cout << "correct password";
            }
            else {
                cout << "wrong password";
            }
        }
        else {
            cout << "wrong username";
        }
    }
    // only Zeus can access the following
     private:
        string password = "password1234";
        string username = "zeus@mtolympus.com";
        bool authenticate;
        
};


int main(){
    loginZeus loginZuesObject;
    loginZuesObject.login();
}