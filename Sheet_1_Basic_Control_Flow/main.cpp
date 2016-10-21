//# is Preprocessor directive, special line interpreted before the compilation of the program,
//directive #include <iostream>, tells preprocessor to include a section of standard C++ code, known as header iostream, 
//lets us perform standard input and output operations, such as writing the output of this program(Hello World) to the screen.
#include <iostream>

//useful library functions for performing "console input and output" 
#include <conio.h> 

#include <string>
#include <typeinfo>

//A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it.
//Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your
//code base includes multiple libraries.
using namespace std; 


//function definitions
void task_1_c();
void task_2_a();
int min(int a, int b);
int max(int a, int b);
int abs(int a);
int square(int a);
int mean(int a, int b);
void task_2_b_c();
void execute_loops();
int sum_first_N(int n);
int sum_first_N_extra(int n);
void fib_loop(int n);
void task_3();
int fib_recursion(int n);
int cal_bi(int n, int i);
void print_pascal();
void task_4();


//int is the return type of the function main
//main is the name of the function ... this is where the program enters first
//argc (argument count) and argv (argument vector) ... command line arguments
//argv size is usually 1 more than argc because mostly implementations add program name to the array
int main(int argc, char** argv)
{ // starts the scope/body of the function
	
	cout << "Hello world" << endl <<endl ; // cout: standard character output stream ... << insertion operator ... "Hello World" is the content in quotes 

// Task calls
	//task_1_c();
	//task_2_a();
	//task_2_b_c();
	//task_3();
	task_4();

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

void task_2_a()
{
	int i = 10;
	int j = 23;
	float f = 3.141f;
	double d = 2.718281828459045;

	cout << endl;
	cout << i / j << " , type: " << typeid(i/j).name() << endl;
	cout << j / i << " , type: " << typeid(j / i).name() << endl;
	cout << i / 2 << " , type: " << typeid(i / 2).name() << endl;
	cout << j / 2 << " , type: " << typeid(j / 2).name() << endl;
	cout << i % 2 << " , type: " << typeid(i % 2).name() << endl;
	cout << j % 2 << " , type: " << typeid(j % 2).name() << endl;
	cout << (j / 3) * 3 + j % 3 << " , type: " << typeid((j / 3) * 3 + j % 3).name() << endl;
	cout << f*f * 5 << " , type: " << typeid(f*f * 5).name() << endl;
	cout << f / d << " , type: " << typeid(f*f * 5).name() << endl;
	cout << d / f << " , type: " << typeid(f / d).name() << endl;
	cout << d*i << " , type: " << typeid(d*i).name() << endl;
	cout << d / i << " , type: " << typeid(d / i).name() << endl<<endl;

	cout << f * d << " , type: " << typeid(f*d).name() << endl;
}

int min(int a, int b)
{
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int abs(int a)
{
	return a < 0 ? -a : a;
}

int square(int a)
{
	return a*a;
}

int mean(int a, int b)
{
	return (a + b) / 2;
}

void task_2_b_c()
{
	cout << mean(min(max(10, 1), abs(-9)), 6) << endl;
}

void execute_loops()
{

	cout << "Using for loop" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "This is the " << i << " th time !" << endl;
	}

	cout << "Using do while loop" << endl;
	int a = 0;
	do{
		cout << "This is the " << a << " th time !" << endl;
		a++;
	} while (a < 10);

	cout << "Using modified while loop" << endl;
	a = 0;
	while (true){
		if (a > 9) break;
		cout << "This is the " << a << " th time !" << endl;
		a++;
	}
}

int sum_first_N(int n)
{
	int sum = 0;

	for (int i = 1; i < n + 1; i++){
		sum += i;
	}

	return sum;
}

int sum_first_N_extra(int n)
{
	return (n*(n+1))/2;
}

void fib_loop(int n)
{
	int num = 0;
	int num2 = 1;
	int fibonacci;

	for (int i = 0; i < n; i++)
	{
		fibonacci = num + num2;
		num = num2;
		num2 = fibonacci;
	}

	cout << "Loop runs "<<n<< " times and we get "<< num << " which is at position " << n+1 << " in fibonacci series."<< endl;
}

void task_3()
{
	//execute_loops();
	//cout<<sum_first_N(500)<<endl;
	//cout << sum_first_N_extra(500) << endl;
	fib_loop(7);
}


int fib_recursion(int n)
{
	if (n == 0 || n == 1){
		return n;
	}
	return fib_recursion(n - 1) + fib_recursion(n - 2);
}

int cal_bi(int n, int i)
{
	if (n == 1 && i == 1){
		return 1;
	}

	if (i == 0){
		return 1;
	}

	if (i == n){
		return 1;
	}

	return cal_bi(n - 1, i - 1) + cal_bi(n - 1, i);
}

void print_pascal()
{
	for (int i = 0; i < 6; i++){
		for (int j = 0; j <=i; j++)
		{
			cout << cal_bi(i, j) << " " << flush;
		}
		cout << endl;
	}
}

void task_4()
{

	//cout<<fib_recursion(1)<<endl;
	//cout<<fib_recursion(5)<<endl;
	//cout<<fib_recursion(6)<<endl;
	//cout<<fib_recursion(100)<<endl; // fails, the buffer in cpu cache gets overflown

	//cout<<cal_bi(5,2)<<endl;

	print_pascal();
}