# hand-of-zeus

![picture of Zues](https://i.pinimg.com/originals/a0/9b/f2/a09bf213e173fd54848d3e17ecd127a2.jpg)
---
Hand of Zues is a C++ management system. Zues, the admin, is able to perform different oporations to change the systems' data. C++ libraries will be used to track operations that create a new entry, delete an entry, or edit an entry within the database. The user will also be able to edit their username and password. 

---
## Installation Instruction

**IMPORTANT** This project was completed on a MacOS and did not use Windows or Linux. Your installation may be different if you used either of those oporating systems. **IMPORTANT**

#### Mac Installation
1. Fork and Clone this repositiory.
2. Open the `terminal` and type the command `g++`
        1. If you get an error, similar to `clang: error: no input files` this means you are set up correctly.
        2. If there is no error, you will be prompted to install developer tools, install and run `g++` again to revieve the above error
3. Once you have the repo forked and cloned down, in your terminal navigate to the folder. Once within the folder run `g++ main.cpp` in your terminal. This will compile the code.
        1. During compiling, if you are using a seperate oporating system than MacOs, you may recive errors in your terminal. That will need to be addressed before the next step.
4. Once the code is compiled, a `a.out` file will be created. `a.out` is the executable program and can be run but typing `./a.out` in the terminal. 
5. Have fun!
___
![Main Menu, Hand of Zeus](https://user-images.githubusercontent.com/108956371/199040889-f2f5fcea-df9d-4df5-91c8-dc71224dee74.png)
___
![Home Screen, Hand of Zeus](https://user-images.githubusercontent.com/108956371/199040926-57f4911a-1768-4a5b-8d88-55c14122fea6.png)

___
# Video Demo


https://user-images.githubusercontent.com/108956371/199314719-b574cc18-59b7-42e9-8284-6534014b47f6.mov


___
## Technologies used

* C++
* Visual Studios Code (C++ Compiler)

C++ was used to program the entire management system. VS Code was used as my compiler for the project to run my program within my terminal using the `g++` command. Object oriented programming was utalized to create a fast and efficient system to manage data as the user sees fit. The following C++ libraries were used:
1. iostream
    1. `iostream` is used for standard input/output stream objects; such as `cin` and `cout`
2. fstream
    1. `fstream` is an input/output stream class to operate on files. This was used to access my `.txt` files and be able to manipulate and read them to update and display data.
3. vector
    1. `vector` was included when I was brainstorming using a `.csv` file to store my data and have it seperated in with commas. The `vector` library would have been used to clasify the data type vector and be able to create vectors from my input data, to then manipulate through index numbers, as vectors are sequence containers.
4. string
    1. `string` introduces string types, character traits and a set of converting functions. These functions can range from converting a string to an integer using `stoi` or `to_string` which converts numbers to a string. In C++ every character is assigned a numerical value, and those values can be compared using the string library.
5. stdio.h
    1. `stdio.h` was used to perform Input/Output operations on my files. For example the `remove` and `rename` function are from this library. You can also use `printf` to print formatted data to stdout, similar to a `console.log` in javascript to check your work as you code.
6. stdlib.h
    1. `stdlib.h` defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting. For the purpose of my project it was used to call the `exit()` function to end the program.
7. sstream
    1. `sstream` is a library that provides string stream classes. For the purpose of my project, this allowed me to use `.eof()` and in creating my system I also tickered with the `getline()` function, both are within the `sstream` library

---
# User Stories

## An admin should be able to:
1. log in and be authorized for app function
2. be able to create a new data entry, delete an entry, and edit an entry.
3. See the data displayed.
4. log out.

---
# My Approach

Going into this project, I had no clue where to start with C++. I had only seen it on job applications and knew that it was powerful enough for Google to use the language in their development. I researched starter C++ projects on GeeksForGeeks, and decided on a management system because I see the applicability of it across many fields.

I created a timeline and challenged myself to be realistic in learning a new language and tackling a bigger project. I watched over 18 hours of lecture on C++ along with code alongs to familiarize myself with C++ libraries and methods and syntax. This was probably my favorite part, because I haven't done as extensive of a deep dive as this before. 

After doing research and watching lectures, I decided to start small and work my way out. I started by creating a basic user authentication and authorization method, and then started to fill out my functionality for my program. Once I completed the bones of my project I was able to style it--in a way--and put my personal touch on it. I was a Classics major in college and was happy to create a Greek and Roman themed project to show my love for ancient Mediterranean religion.
___
# Unsolved Problems and Major Hurdles

* Without a doubt, one of my biggest challenges was using MacOs as my operating system. I came to learn that Lenux and Windows are used exponentially more that MacOs is the creating of C++ programs. With that comes Windows and Linux specific C++ libraries that I don't have access to, meaning common methods and solutions to problems did not work for my operating system. I had to rethink many many elements of my project because of this and spent more time than I expected trouble shooting ways to make MacOS work with the research and lectures I found.
* I also spent 2-3 days trying to store my data in a `.csv` file. Methodically I was writing correct code that **should** have performed correctly. But I came to find out that `.csv` files are much more delecate and complex than I had originally thought. I spent so much time trouble shooting my edit and delete functions but continuously would break my computer or get stuck in endless loops due to vector strings made up of `.csv` rows....(YUCK)! I wanted a `.csv` because of the ease to transfer to spreadsheets, but once I switched to a `.txt` file, my code ran smoothy and I was able to complete MVP.
* I wanted to add another input element that could be a "god of:" data point so you could type sentences into the input, but the `getline(cin, __)` kept breaking my program and I couldn't figure out why that was happening.
* I also wanted to make it so that a password would not show when a user was typing it in, but also could not figure that out.
* Editing a user can break my application since an admin can assign the same ID number to different data entries, I was not able to figure out how to fix this, or how to target a data entry by a string(name) instead of by ID(int).
* Syntax is very very different with C++ and I continuously forgot to include punctuation throughout the project, not a hurdle, but an issue I continuously ran into...lots of `;`


---
# Additional Information for an Intro to C++ 
* [W3 Schools Intro to C++](https://www.w3schools.com/cpp/cpp_intro.asp)
* [GeeksforGeeks C++ Introduction](https://www.geeksforgeeks.org/c-plus-plus/)
* [Youtube Intro to C++](https://www.youtube.com/watch?v=OTroAxvRNbw&t=1s)
* [GeeksforGeeks Project Ideas](https://www.geeksforgeeks.org/top-7-cpp-project-ideas-for-beginners/)

---
# Minimum Viable Product(MVP) Goals

- [X] create a system that logs a user in and allows them to manage a system
- [X] create edit/delete/create for a datapoint "god" that the admin can edit
- [X] create an auth for the admin

# Unexpected Achievements

- [X] allowing the admin to edit and change their username and password
- [X] Creating a registration element for the admin and allowing an admin to delete their account.

# Stretch Goals

- [ ] set up HTML to show my database using WebAssembly
- [ ] allow specific users to log in and edit their information but not other users and have different options than an admin
