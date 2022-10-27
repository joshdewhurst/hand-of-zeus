#include <iostream>
// including file stream to get info to and from the disk and the program
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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
                    break;
                case 3:
                    cout << "delete a god";
                    deleteGod();
                    break;
                case 4: 
                    cout << "see all gods";
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
        fstream file("gods.csv", ios::out | ios::in);
        if (file)
        {
            cout << "\n\n\n\t\t\t Welcome, please input new god information. \n" << endl;
            string godName;

            cout << "please enter the god's name: \n" << endl;
            cin >> godName;
            // inserting the godName into a file, but putting a new line for each new god that is created
            file << godName << ',' << "\n";
            file.close();
        }
        else{
            cout << "unable to acces creation file, try again";
            addGod();
        }
        menu();
    }

    void deleteGod()
    {
        fstream fin, fout;

        // opening the file with the data
        fin.open("gods.csv", ios::in);

        // creating a new file to place non-deleted data
        fout.open("godsNotDeleted.csv", ios::out);

        string line, word;
        char sub;
        int index, godName, god1, i, count = 0;
        vector<string>  row;


        // use the name to find the god
        cout << "What god will be sent to Tartarus?";
        cin >> godName;
        cout << godName;

        // while loop that will continue to run until the end of the file is reached
        while (!fin.eof())
        {
            row.clear();
            getline(fin, line);
            // breaking the words in a string
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int row_size = row.size();
            god1 = stoi(row[0]);

            if (god1 != godName)
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++) {
                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                count = 1;
            }
            if (fin.eof())
                break;
        }
        if (count == 1)
        cout << "god was deleted \n";
        else
        cout << "record was not found \n";

        fin.close();
        fout.close();

        remove("gods.csv");
        rename("godsNotDeleted.csv", "gods.csv");
    }

    void login(){
        // cout is a response in console
        cout << "please enter your almighty name \nUsername:";
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
        bool authenticate;
        
};

int main(){
    loginZeus loginZuesObject;
    loginZuesObject.login();

    cin.get();
}