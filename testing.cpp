#include <iostream>
#include <climits>

// creating a namespace to track libraries
using std::cout;
using std::cin;
using std::string;

int main() {

//     // creating a data type string
//   string name;
// //   console out the name variable
//     cout << "what is the name of the god?";
//     cin >> name;
//     cout << "the name of the god is " << name;

// integral data types
short a;
int b;
long c;
long long d;
// short <= int <= long <= long long
unsigned short aa;
unsigned int bb;
unsigned long cc;
unsigned long long dd;

char x = 'A';
// cout << x << std::endl;
// all characters have numbers associated with them through the askby table

cout << "Hello\tThere" << std:: endl; //back slash t allows a tab
cout << "hello\nthere" << std:: endl; //backslash n does a new line
cout << "hello\0"; // null character that ends a C style string
cout << "hello \"there\" ' ";
}
