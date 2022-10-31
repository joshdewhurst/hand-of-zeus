#include <iostream>
// including file stream to get info to and from the disk and the program
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#define MAX_GOD_OF 250

using namespace std;
// using the standard library for naming

class loginZeus{
    // public keyword, meaning anyone can access
    public:
        loginZeus(){
            authenticate = false;
        };

// main menu function that will only render if logged in
    void menu()
        {
            system("clear"); //clearing the screen
            cout << "\n\n\n\t\t\t Welcome back:" << username ;
            cout << "\n\n\n\t\t What would you like to do?";
            cout << "\n\n\n\t\t 1. Create a god";
            cout << "\n\n\n\t\t 2. Edit a god";
            cout << "\n\n\n\t\t 3. Delete a god";
            cout << "\n\n\n\t\t 4. See all gods";

            int selection;
            cin >> selection;
            // switch expressions have cases to choice from 
            switch (selection)
            {
                case 1:
                    cout << "\n\n\n\t\t\t create a god" << endl;
                    addGod();
                    break;
                case 2:
                    cout << "edit a god";
                    editGod();
                    break;
                case 3:
                    cout << "delete a god";
                    deleteGod();
                    break;
                case 4: 
                    cout << "see all gods";
                    showGods();
                    break;
                default:
                    cout << "ivalid choice, for the gods sake try again";
                    menu();
            }
        }

    void addGod()
    {
    // clearing the system
        system("clear");
        fstream file;
        if (file)
        {
            cout << "\n\n\n\t\t\t Welcome, please input new god information. \n" << endl;

            cout << "\t\t please enter the god Id [max 6 digets]: \n" << endl;
            cin >> godId;
            cout << "\t\t please enter the god's name: \n" << endl;
            cin >> godName;
            cout << "\t\t What is their roman name? \n";
            cin >> romanName;
            cout << "\t\t What are they the god of? \n";
            cin.ignore();
            getline(cin, godOf);

            // inserting the godName into a file, but putting a new line for each new god that is created
            file.open("gods.txt", ios::out | ios::app);
            file << godId << " " << godName << " " << romanName << " " << godOf << "\n";
            file.close();
        }
        else{
            cout << "unable to acces creation file, try again";
            addGod();
        }
        menu();
    }

    void editGod()
    {
        fstream file, newFile;
        int matchId;
        int found = 0;
        string name, roman;
        int id;

        cout << "\n\t\t Edit a god";
        cout << "\n\t\t What is the god's ID?";
        cin >> matchId;

        file.open("gods.txt", ios::in);
        if (!file)
        {
            cout << "\n\t\t\t The gods are at it again...the file is lost";
            file.close();
        }
        else
        {
            newFile.open("newGods.txt", ios::app | ios::out);

            file >> godId >> godName >> romanName;

            while (!file.eof())
            {
                if (matchId == godId)
                {
                    cout << "\n\t What is the god's new ID?";
                    cin >> id;
                    cout << "\n\t What is the god's new Greek name?";
                    cin >> name;
                    cout << "\n\t What is the god's new Roman name?";
                    cin >> roman;
                    newFile << " " << id << " "<< name << " " << roman << "\n";
                    cout << "\n\t\t God was edited!";
                    found ++;
                }
                else 
                {
                    cout << "God not found";
                    newFile << " " << godId << " " << godName << " " << romanName << "\n";
                }
                file >> godId >> godName >> romanName;
            }
            file.close();
            newFile.close();

            remove("gods.txt");
            rename("newGods.txt","gods.txt");

            menu();
        }
    }

    void deleteGod()
    {
        system("clear");
        int matchId;
        fstream file, newFile;
        int found = 0;
        cout << "\t\t\t Delete a God \t\t\t\n";
        // opening the gods file, ios::in reads, ios:out operation
        file.open("gods.txt", ios::in);
        if(!file)
        {
            cout << "\n\t\t\t The gods are at it again...the file is lost";
            file.close();
        }
        else
        {
            cout << "Please enter the god ID of the god you are sending to Tartarus:";
            cin >> matchId;
            newFile.open("newGods.txt", ios::app | ios::out);
            file >> godId >> godName >> romanName;
            while (!file.eof())
            {
                if (godId == matchId)
                {
                    cout << "\n\t\t God was banished";
                    found++;
                } else 
                {
                    newFile << " " << godId << " " << godName << " " << romanName << '\n';
                }
                file >> godId >> godName >>romanName;
            }
            newFile.close();
            file.close();
            remove("gods.txt");
            rename("newGods.txt", "gods.txt");
            menu();
        }
    }

    void showGods()
    {
        fstream file;
        file.open("gods.txt", ios::in);
        cout << "\n\n|________________________________\n";
        cout << "God Id\t\tGreek Name\t\tRoman Name\n";
        cout << "\n\n|________________________________\n";
        file >> godId >> godName >> romanName;
        while (!file.eof())
        {
            cout << godId << "\t\t" << godName << "\t\t" << romanName << "\n";
            file >> godId >> godName >> romanName;
        }
        file.close();
    }

    void login(){
        // cout is a response in console

        cout << "\t\t\t\t____________________________________________\n";
        cout << "\t\t\t\t                                            \n";
        cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
        cout << "\t\t\t\t                                            \n";
        cout << "\t\t\t\t____________________________________________\n";


        cout << "\t please enter your almighty name username: \n";
        // cin is input from user
        cin >> usernameMatch;

        // retreaving the username from a file
        username = getFile("users.txt");

        if(usernameMatch == username){
            cout << "\t\t\t please enter the almighty password: \n";
            cin >> passwordMatch;

            password = getFile("password.txt");

            if(passwordMatch == password) {
                cout << "correct password";
                menu();
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
        string godOf;
        bool authenticate;
        int godId;
        char godName[20];
        char romanName[20];
        
};

int main(){
    loginZeus loginZuesObject;
    loginZuesObject.login();

    cin.get();
}