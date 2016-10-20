//# is Preprocessor directive, special line interpreted before the compilation of the program,
//directive #include <iostream>, tells preprocessor to include a section of standard C++ code, known as header iostream, 
//lets us perform standard input and output operations, such as writing the output of this program(Hello World) to the screen.
#include <iostream>

//useful library functions for performing "console input and output" 
#include <conio.h> 

#include <string>

//A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it.
//Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your
//code base includes multiple libraries.
using namespace std; 

void task_1_c();

//int is the return type of the function main
//main is the name of the function ... this is where the program enters first
//argc (argument count) and argv (argument vector) ... command line arguments
//argv size is usually 1 more than argc because mostly implementations add program name to the array
int main(int argc, char** argv)
{ // starts the scope/body of the function
	
	cout << "Hello world" << endl; // cout: standard character output stream ... << insertion operator ... "Hello World" is the content in quotes 

	//task_1_c
	task_1_c();

	_getch(); // a function from conio header ... used to get character from the user
	return 0; // return statement of the function
} // ends the scope/body of the function

void task_1_c()
{
	string name;
	int day, month, year;
	int cday = 29, cmonth = 4, cyear = 2016;

	cout << "Enter your name: " << flush; // flush clears the buffer
	getline(cin, name); // becuase extraction operator >> does not take spaces

	cout << "Enter your day of birth: " << flush;
	cin >> day;

	cout << "Enter your month of birth: " << flush;
	cin >> month;

	cout << "Enter your year of birth: " << flush;
	cin >> year;

	cout << "Hi, " << name << ".\nYour age is:" << cyear - year << endl;

}