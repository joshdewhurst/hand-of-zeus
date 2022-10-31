# hand-of-zues

![picture of Zues](https://i.pinimg.com/originals/a0/9b/f2/a09bf213e173fd54848d3e17ecd127a2.jpg)
---
Hand of Zues will be a C++ database management system. Zues, the admin, is able to perform different oporations to change the systems' data. C++ libraries will be used to track operations that create a new entry, delete an entry, or edit an entry within the database. The user will also be able to edit their username and password. 

---
## Technologies used

* C++
* Visual Studios Code (C++ Compiler)

C++ was used to program the entire management system. VS Code was used as my compiler for the project to run my program within my terminal using the `g++` command. Object oriented programming was utalized to create a fast and efficient system to manage data as the user sees fit. The following C++ libraries were used:
1. iostream
    1. `iostream` is used for standard input/output stream objects; such as `cin` and `cout`
2. fstream
  i. `fstream` is an input/output stream class to operate on files. This was used to access my `.txt` files and be able to manipulate and read them to update and display data.
3. vector
  i. `vector` was included when I was brainstorming using a `.csv` file to store my data and have it seperated in with commas. The `vector` library would have been used to clasify the data type vector and be able to create vectors from my input data, to then manipulate through index numbers, as vectors are sequence containers.
4. string
  i. `string` introduces string types, character traits and a set of converting functions. These functions can range from converting a string to an integer using `stoi` or `to_string` which converts numbers to a string. In C++ every character is assigned a numerical value, and those values can be compared using the string library.
5. stdio.h
  i. `stdio.h` was used to perform Input/Output operations on my files. For example the `remove` and `rename` function are from this library. You can also use `printf` to print formatted data to stdout, similar to a `console.log` in javascript to check your work as you code.
6. stdlib.h
  i. `stdlib.h` defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting. For the purpose of my project it was used to call the `exit()` function to end the program.
7. sstream
  i. `sstream` is a library that provides string stream classes. For the purpose of my project, this allowed me to use `.eof()` and in creating my system I also tickered with the `getline()` function, both are within the `sstream` library



---
# User Stories

## An admin should be able to:
1. log in and be authorized for app function
2. be able to create a new entry, delete an entry, and edit and entry
3. See the data displayed
4. log out

---
# Week Planner
![My Week Planned](https://user-images.githubusercontent.com/108956371/197700614-0ffb2559-b1fe-4c15-8dc8-2a7494b9b3fb.png)

---
# Additional Information
* [W3 Schools Intro to C++](https://www.w3schools.com/cpp/cpp_intro.asp)
* [GeeksforGeeks C++ Introduction](https://www.geeksforgeeks.org/c-plus-plus/)
* [Youtube Intro to C++](https://www.youtube.com/watch?v=OTroAxvRNbw&t=1s)
* [GeeksforGeeks Project Ideas](https://www.geeksforgeeks.org/top-7-cpp-project-ideas-for-beginners/)

---
# MVP Goals

- [X] create a system that logs a user in and allows them to manage a system
- [X] create edit/delete/create for a datapoint "god" that the admin can edit
- [X] create an auth for the admin

# Stretch Goals

- [X] set up HTML to show my database using WebAssembly
- [X] allow specific users to log in and edit their information but not other users and have different options than an admin
