#include <iostream>
// including file stream to get info to and from the disk and the program
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
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
            
            cout << "\n\n\n\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t                 Main Menu                  \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";
            cout << "\n\n\n\t\t 1. Create a god";
            cout << "\n\n\n\t\t 2. Edit a god";
            cout << "\n\n\n\t\t 3. Delete a god";
            cout << "\n\n\n\t\t 4. Search for a god";
            cout << "\n\n\n\t\t 5. See all gods";
            cout << "\n\n\n\t\t 6. Admin Settings";
            cout << "\n\n\n\t\t 7. Exit program \n\n\n";

            int selection;
            cin >> selection;
            // switch expressions have cases to choice from 
            switch (selection)
            {
                case 1:
                    addGod();
                    break;
                case 2:
                    editGod();
                    break;
                case 3:
                    deleteGod();
                    break;
                case 4:
                    searchGod();
                    break;
                case 5: 
                    showGods();
                    break;
                case 6:
                admin();
                break;
                case 7:
                    exit(0);
                    break;
                default:
                    cout << "\t\t\t\t ivalid choice, for the gods sake try again";
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
            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t            Creating a New God:             \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n\n\n\n";

            string createchoice;
            cout << "\n\n\t\t\t\t Would you like to proceed with creating a god? (Y or N)\n\n";
            cin >> createchoice;

            if (createchoice == "y" | createchoice == "Y")
            {
                cout << "\n\n\t\t please enter the god Id [max 6 digets]: \n\n" << endl;
                cin >> godId;
                cout << "\t\t please enter the god's name: \n" << endl;
                cin >> godName;
                cout << "\t\t What is their roman name? \n";
                cin >> romanName;
                // godOf messed the whole system up for some reason
                // cout << "\t\t What are they the god of? \n";
                // cin.ignore();
                // getline(cin, godOf);

                // inserting the godName into a file, but putting a new line for each new god that is created
                file.open("gods.txt", ios::out | ios::app);
                file << godId << " " << godName << " " << romanName <<  "\n";
                file.close();
            }
            else if (createchoice == "n" | createchoice == "N")
            {
                menu();
            }
            else 
            {
                cout << "\n\t\t\t\t Invalid Input, returning to main menu.";
                menu();
            }
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

            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t          Edit and Existing God:            \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n\n\n\n";

            string editchoice;
            cout << "\n\n\t\t\t\t Would you like to proceed with deleting a god? (Y or N)\n\n";
            cin >> editchoice;

            if (editchoice == "y" | editchoice =="Y")
            {
                cout << "\n\t\t What is the god's id";
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
            else if (editchoice == "n" | editchoice == "N")
            {
                menu();
            }
            else 
            {
                cout << "\n\t\t\t\t Invalid Input, returning to main menu.";
                menu();
            }    
     }

    void deleteGod()
    {
        system("clear");
        int matchId;
        fstream file, newFile;
        int found = 0;

            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t              Deleting a God:               \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";

        // opening the gods file, ios::in reads, ios:out operation
        file.open("gods.txt", ios::in);
        if(!file)
        {
            cout << "\n\t\t\t The gods are at it again...the file is lost";
            file.close();
        }
        else
        {
            string deletechoice;
            cout << "\n\n\t\t\t\t Would you like to proceed with deleting a god? (Y or N)\n\n";
            cin >> deletechoice;

            if (deletechoice == "y" | deletechoice =="Y")
            {
                cout << "\n\n\t\t\t\t Please enter the god ID of the god you are sending to Tartarus:\n\n";
                cin >> matchId;
                newFile.open("newGods.txt", ios::app | ios::out);
                file >> godId >> godName >> romanName;
                while (!file.eof())
                {
                    if (godId == matchId)
                    {
                        cout << "\n\t\t\t\t God was banished";
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
                string banishinput;
                cout << "\n\n\t\t\t\t Would you like to banish another god? (Y or N) \n\n";
                cin >> banishinput;
                if (banishinput == "Y" | banishinput == "y" | banishinput == "yes" | banishinput == "Yes")
                {
                    deleteGod();
                }
                else if (banishinput == "N" | banishinput == "n" | banishinput == "No" | banishinput == "no")
                {
                    string secondChoice;
                    cout << "\n\t\t\t\t Hit A to return to main menu, hit B exit program \n";
                    cin >> secondChoice;
                    if (secondChoice == "a" | secondChoice =="A")
                    {
                    menu();
                    }
                    else if(secondChoice == "b" | secondChoice == "B")
                    {
                        exit(0);
                    }
                    else{
                    cout << "\n\t\t\t\t Invalid input, redirecting to See All Gods";
                    showGods();
                    }
                }
                else {
                    cout << "/n/n/t/t/t/t Invalid Input, returning to Delete Gods";
                }
            }
            else if (deletechoice == "n" | deletechoice == "N")
            {
                menu();
            }
            else 
            {
                cout << "\n\t\t\t\t Invalid Input, returning to main menu.";
                menu();
            }
        }
    }

    void searchGod()
    {
        system("clear");
            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t             Search for a God:              \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";

            fstream file;
            int matchId;

            string searchchoice;
            cout << "\n\n\t\t\t\t Would you like to proceed with searching for a god? (Y or N)\n\n";
            cin >> searchchoice;

            if (searchchoice == "y" | searchchoice =="Y")
            {
                cout << "\n\t\t What is the god's id \n\n";
                cin >> matchId;

                file.open("gods.txt", ios::in);
                if(!file)
                {
                    cout << "\n\t\t\t The gods are at it again...the file is lost";
                    file.close();
                }
                else 
                {
                    int c=0;
                    file >> godId >> godName >> romanName;
                    while (!file.eof())
                    {
                        if (matchId == godId)
                        {
                            cout << "\n\n\n God Id\t\tGreek Name\t\tRoman Name\t\t\n";
                            cout << "\n\n";
                            cout << godId << "\t\t" << godName << "\t\t" << romanName << "\n";
                            c++;
                        }
                        file >> godId >> godName >> romanName;
                    }
                    if (c == 0)
                    {
                        cout << "\n\t\t\t\t The god with that Id was not found.";
                        string tryagain;
                        cout << "\n\n\t\t\t\t Would you like to try to search again? (Y or N)";
                        cin >> tryagain;
                        if (tryagain =="y" | tryagain == "Y"){
                            searchGod();
                        }
                        else {
                            menu();
                        }
                    }
                    file.close();
                    string searchagain;
                    cout << "\n\n\t\t\t\t Would you like to try to search again? (Y or N)";
                    cin >> searchagain;
                    if (searchagain =="y" | searchagain == "Y"){
                            searchGod();
                        }
                    else if (searchagain == "n" | searchagain == "N") {
                            menu();
                        }
                    else 
                    {
                        cout << "\n\n\t\t\t\t Invalid input, redirecting to main menu.";
                        menu();
                    }
                }
            }
            else if (searchchoice == "n" | searchchoice == "N")
            {
                string secondChoice;
                    cout << "\n\t\t\t\t Hit A to return to main menu, hit B exit program \n";
                    cin >> secondChoice;
                    if (secondChoice == "a" | secondChoice =="A")
                    {
                    menu();
                    }
                    else if(secondChoice == "b" | secondChoice == "B")
                    {
                        exit(0);
                    }
                    else{
                    cout << "\n\t\t\t\t Invalid input, redirecting to See All Gods";
                    showGods();
                    }
            }
            else 
            {
                cout << "\n\n\t\t\t\t Invalid Input, directing to main menu.";
                menu();
            }
    }

    void showGods()
    {
        system("clear");
        string choice;
        
        fstream file;
        file.open("gods.txt", ios::in);

            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t             Showing All Gods:              \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";

        cout << "\n\t\t Would You like to see a list of all gods? (Y or N)";
        cin >> choice;

        if (choice == "y" | choice =="Y")
        {
            system("clear");
            cout << "\n\n\n God Id\t\tGreek Name\t\tRoman Name\t\t\n";
            cout << "\n\n";
            file >> godId >> godName >> romanName;
            while (!file.eof())
            {
                cout << godId << "\t\t" << godName << "\t\t" << romanName << "\n";
                file >> godId >> godName >> romanName;
            }
            file.close();

            string menuinput;
            cout << "\n\t\t Type -Menu- to return to main menu \n\n";
            cin >> menuinput;
            if (menuinput == "menu" | menuinput == "Menu" | menuinput == "-menu-" | menuinput == "-Menu-")
            {
                menu();
            }
        }
        else 
        {
            string secondChoice;
            cout << "\n\t\t\t\t Hit A to return to main menu, hit B exit program \n";
            cin >> secondChoice;
            if (secondChoice == "a" | secondChoice =="A")
            {
                menu();
            }
            else if(secondChoice == "b" | secondChoice == "B")
            {
                exit(0);
            }
            else{
                cout << "\n\t\t\t\t Invalid input, redirecting to See All Gods";
                showGods();
            }
        }
    }

    void admin()
    {
        cout << "\t\t\t\t____________________________________________\n";
        cout << "\t\t\t\t                                            \n";
        cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
        cout << "\t\t\t\t              Admin Settings:               \n";
        cout << "\t\t\t\t                                            \n";
        cout << "\t\t\t\t____________________________________________\n";

        cout << "\n\n\t\t\t\t You are currently logged in as the kind of the gods:" << "\n\t\t\t\t" << username;

        cout << "\n\n\t\t\t\t What would you like to do?";

        cout << "\n\n\n\t\t 1. Edit Username";
        cout << "\n\n\n\t\t 2. Edit Password";
        cout << "\n\n\n\t\t 3. Return to Main Menu";
        cout << "\n\n\n\t\t 4. Log Off Program \n\n";
        cout << "\n\n\n\t\t 5. Delete Your Account \n\n";

        int selection;
            cin >> selection;
            // switch expressions have cases to choice from 
            switch (selection)
            {
                case 1:
                    editUsername();
                    break;
                case 2:
                    editPassword();
                    break;
                case 3:
                    menu();
                    break;
                case 4:
                    exit(0);
                    break;
                case 5:
                    deleteUser();
                    break;
                default:
                cout << "\t\t\t\t ivalid choice, for the gods sake try again";
                admin();
            }
    }

    void editUsername()
        {
            system("clear");
            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t       Admin Settings: Edit username        \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";

            

            cout << "\n\n\t\t\t\t Your current username is: \t\t" << username << "\n";
            string newusername;

            cout << "\n\n\t\t\t\t What would you like your new username to be? \n\n";
            cin >> newusername;

            fstream file;
            file.open("newUsers.txt", ios::out | ios::app);
            file << newusername << "\n";
            file.close();

            remove("users.txt");
            rename("newUsers.txt","users.txt");
            
            cout << "\n\n\t\t\t\t Your username was succesfully updated to: \n\t\t\t\t" << newusername;
            username = getFile("users.txt");
            
            string menuinput;
            cout << "\n\t\t Type -Admin- to return to admin settings \n\n";
            cin >> menuinput;
            if (menuinput == "admin" | menuinput == "Admin" | menuinput == "-admin-" | menuinput == "-Admin-")
            {
                admin();
            }
            else 
            {
                cout << "\n\n\t\t\t\t Invalid Input, redirecting to Main Menu.\n";
                menu();
            }
        
        }

    void editPassword()
    {
        system("clear");
            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t       Admin Settings: Edit Password        \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";

            
            string newpassword, matchPassword;

            cout << "\n\n\t\t\t\t Please Enter Your Current Password: \n";
            cin >> matchPassword;
            if (matchPassword == password)
            {
                cout << "\n\n\t\t\t\t What would you like your new password to be? \n\n";
                cin >> newpassword;

                string passwordCheck;
                cout << "\n\n\t\t\t\t Please re-enter new password. \n\n";
                cin >> passwordCheck;

                if (newpassword == passwordCheck)
                {
                    fstream file;
                    file.open("newpassword.txt", ios::out | ios::app);
                    file << newpassword << "\n";
                    file.close();

                    remove("password.txt");
                    rename("newpassword.txt","password.txt");
                    
                    cout << "\n\n\t\t\t\t Your password was succesfully updated! \n";
                    password = getFile("password.txt");
                    
                    string menuinput;
                    cout << "\n\t\t Type -Admin- to return to admin settings \n\n";
                    cin >> menuinput;
                    if (menuinput == "admin" | menuinput == "Admin" | menuinput == "-admin-" | menuinput == "-Admin-")
                    {
                        admin();
                    }
                    else 
                    {
                        cout << "\n\n\t\t\t\t Invalid Input, redirecting to Main Menu. \n";
                        menu();
                    }
                }
                else
                {
                    // setting newpassword to null and having the user start over
                    newpassword = "";
                    cout << "\n\n\t\t\t\t Passwords did not match, please try again \n\n";
                    editPassword();
                }
            }
            else
            {
                cout << "\n\n\t\t\t Invalid Input. \n";
                editPassword();
            }
    }

    void deleteUser()
    {
        system("clear");
            cout << "\t\t\t\t____________________________________________\n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
            cout << "\t\t\t\t        Admin Settings: Delete User         \n";
            cout << "\t\t\t\t                                            \n";
            cout << "\t\t\t\t____________________________________________\n";

        string choice;
        cout << "\n\n\t\t\t\t Would you like to delete your account? (Y or N)";
        cin >> choice;
        if (choice == "y" | choice == "Y")
        {
            string choice2;
            cout << "\n\n\t\t\t\tThis is your last chance before we send your information to the fates. \n";
            cout << "\n\t\t\t\tAre you sure you want to delete your account? (Y or N) \n\n";
            cin >> choice2;
            if (choice2 == "y" | choice2 == "Y")
            {
                std::ofstream file1, file2;
                file1.open("password.txt", std::ofstream::out | std::ofstream::trunc); 
                file2.open("users.txt", std::ofstream::out | std::ofstream::trunc);
                file1.close();
                file2.close();
                login();
            }
            else if (choice2 == "n" | choice2 == "N")
            {
                string menuinput;
                cout << "\n\t\t Type -Admin- to return to admin settings \n\n";
                cin >> menuinput;
                if (menuinput == "admin" | menuinput == "Admin" | menuinput == "-admin-" | menuinput == "-Admin-")
                {
                    admin();
                }
                else 
                {
                    cout << "\n\n\t\t\t\t Invalid Input, redirecting to Main Menu.\n";
                    menu();
                }
            }
        }
        else if (choice == "n" | choice == "N")
        {
            string menuinput;
            cout << "\n\t\t Type -Admin- to return to admin settings \n\n";
            cin >> menuinput;
            if (menuinput == "admin" | menuinput == "Admin" | menuinput == "-admin-" | menuinput == "-Admin-")
            {
                admin();
            }
            else 
            {
                cout << "\n\n\t\t\t\t Invalid Input, redirecting to Main Menu.\n";
                menu();
            }
        }
        else 
            {
                cout << "\n\n\t\t\t\t Invalid Input, redirecting to Main Menu.\n";
                menu();
            }
    }

    void login(){
        // cout is a response in console

        cout << "\t\t\t\t____________________________________________\n";
        cout << "\t\t\t\t                                            \n";
        cout << "\t\t\t\t The Hand of Zeus: God Management Systsem   \n";
        cout << "\t\t\t\t                                            \n";
        cout << "\t\t\t\t____________________________________________\n";

        cout << "\n\n\n\t\t The Hand of Zeus is a data management system created completely with C++ and expands on the object oriented programming capabilities of the language. With the Hand of Zeus, the king of the gods can manage the pantheon and help keep the divine organized. Please enjoy the introduction to C++ and some examples of its uses.         \n\n\t\t\t\t\t\t- Josh\n";

        fstream file1, file2;
        ifstream file("users.txt");
        
        file.seekg(0,ios::end); // points to the end of file
        int length = file.tellg();
        
        if (length == 0)
        {
            cout << "\n\n\n\n\t\t\t Admin settings are not yet defined oh mighty Zeus \n";
            string user, pass, pass2;
            cout << "\n\t\t\t\t What shall your username be? \n";
                cin >> user;
                file1.open("users.txt", ios::out | ios::app);
                file1 <<  user << "\n";
                file1.close();
            cout << "\n\t\t\t\t And your password? \n";
            cin >> pass;
            cout << "\n\t\t\t\t Please enter your password once more. \n";
            cin >> pass2;
            if (pass == pass2)
            {
                file2.open("password.txt", ios::out | ios::app);
                file2 <<  pass << "\n";
                file2.close();
                login();
            }
        }
        else
        {
            cout << "\n\n\n\n\t\t\t To begin, please enter your almighty name (username): \n";
            // cin is input from user
            cin >> usernameMatch;

            // retreaving the username from a file
            username = getFile("users.txt");

            if(usernameMatch == username){
                cout << "\n\n\t\t\t\t please enter the almighty password: \n";
                cin >> passwordMatch;

                password = getFile("password.txt");

                if(passwordMatch == password) {
                    cout << "\n\t\t\t\t Welcome Zeus, the power is in your hands.";
                    menu();
                }
                else {
                    cout << "\n\t\t\t\t Incorrect identification, don't get the gods upset. Try again.";
                    login();
                }
            }
            else {
                cout << "wrong username";
                login();
            }
        }
        
    }

    // define a function to retrieve the password and usernames from a stored file
    string getFile(const char* file1)
        {
            string line;
            fstream file;

            file.open(file1, ios::in);
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