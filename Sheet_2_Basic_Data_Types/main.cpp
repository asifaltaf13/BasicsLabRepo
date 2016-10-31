#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int string_length(const char* s){
    int count = 0;

    for(int i=0; s[i]; i++) {
        count ++;
    }
    return count;
}

char map(char ch){
    char output;
    if((int)ch>=97 && (int)ch<=122){
        output = (int)ch - 32;
    }
    else if((int)ch == ' '){
        output = ' ';
    }
    else{
        output = (int)ch + 32;
    }
    return output;
}

int main(int argc, char** argv){
    cout << "*************Assignment 1 c: Listing 1****************" << endl;
    char res = 0;
    for( int c = 0; c < 1000; ++c ) {
        res = res + 1;
    }
    cout << (int) res << std::endl;

    cout << "*************Assignment 1 c: Listing 2****************" << endl;
    // for(unsigned char c=100; c>=0; --c) {

    // 	res = res + 1;
    // }
    // cout << (int) res << std::endl;

    cout << "*************Assignment 2a**************" << endl;
    int a[40];
    for(int i = 0; i<40; i++){
        a[i] = 2*(i+1);
        cout << "a[" << i << "]: " << a[i] << endl;
    }

    cout << "*************Assignment 2b**************" << endl;
    int b[40];
    for(int i =0; i<40; i++){
        b[i] = a[i];
        for(int j=0; j<i; j++){
            b[i] = b[i] + a[j];
        }
        cout << "b[" << i << "]: " << b[i] << endl;
    }


    int d[40];
    for(int i = 0; i < 40; i++){
        d[i] = a[39 - i];
        cout << "d[" << i << "]: " << d[i] << endl;
    }


    // double factorial of even numbers
    int c[8];
    for(int i=0; i<8; i++){
        c[i] = a[i];
        for(int j = 0; j< i; j++){
            c[i] = c[i] * a[j];
        }
        cout << "c[" << i << "]: " << c[i] << endl;
    }

    // cout << "Accessing a:" << endl;
    // cout << "a[6]: " << a[6] << endl;
    // cout << "a[100]: " << a[100] << endl;
    // cout << "a[100000]: " << a[100000] << endl;
    // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

    // cout << "Accessing b:" << endl;
    // cout << "b[6]: " << endl;
    // cout << "b[100]: " << b[100] << endl;
    // cout << "b[100000]: " << b[100000] << endl;
    // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

    // cout << "Accessing c:" << endl;
    // cout << "c[6]: " << c[6] << endl;
    // cout << "c[100]: " << c[100] << endl;
    // cout << "c[100000]: " << c[100000] << endl;
    // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

    // cout << "Accessing d:" << endl;
    // cout << "d[6]: " << d[6] << endl;
    // cout << "d[100]: " << d[100] << endl;
    // cout << "d[100000]: " << d[100000] << endl;
    // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

    cout << "*************Assignment 3**************" << endl;
    char achar;
    int anint;

    cout << "Assignment 3a" << endl;
    cout << "a char: " << achar << endl;
    cout << "an int: " << anint << endl;

    cout << "Assignment 3b" << endl;
    char aa = 'a';
    char bb = 'b';
    char cc = 'c';
    char zz = 'z';
    char aaa = 'A';
    char bbb = 'B';
    char ccc = 'C';
    char zzz = 'Z';
    char zero = '0';
    char one = '1';
    char two = '2';
    char nine = '9';

    cout << "a: " << (int)aa << endl;
    cout << "b:" << (int)bb << endl;
    cout << "c:" << (int)cc << endl;
    cout << "z:" << (int)zz << endl;
    cout << "A:" << (int)aaa << endl;
    cout << "B:" << (int)bbb << endl;
    cout << "C:" << (int)ccc << endl;
    cout << "Z:" << (int)zzz << endl;
    cout << "0:" << (int)zero << endl;
    cout << "1:" << (int)one << endl;
    cout << "2:" << (int)two << endl;
    cout << "9:" << (int)nine << endl;

    char ithletter = 'i';
    cout << "ith letter:" << (int)ithletter << endl;

    cout << "Assignment 3c" << endl;
    char lowercase = 'a';
    cout << "a-z: ";
    for(int i = 0; i<26; i++){
        cout << (int)lowercase << ", ";
        lowercase++;
    }
    cout << endl;
    cout << "A-Z: ";
    char uppercase = 'A';
    for(int i = 0; i<26; i++){
        cout << (int)uppercase << ", ";
        uppercase++;
    }
    cout << endl;
    char number = '0';
    cout << "0-9: ";
    for(int i = 0; i<10; i++){
        cout << (int)number << ", ";
        number++;
    }
    cout << endl;

    cout << "Assignment 3d" << endl;
    const char* message = "Hello world";
    cout << message << endl;

    cout << "Assignment 3e" << endl;
    cout << "The length of Hello_world is: " << string_length(message) << endl;

    cout << "Assignment 3f" << endl;
    char lower = 'a';
    char upper = 'A';

    cout << "lowercase a mapped to: " << map(lower) << endl;
    cout << "uppercase A mapped to: " << map(upper) << endl;

    cout << "Assignment 3g" << endl;
    char buffer[100];// = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaa';

    for(int i = 0; i < 30; i++){
        buffer[i] = 'a';
    }

    cout << "buffer: " << buffer << endl;
    int counter = 0;
    for(counter = 0;  message[counter]; counter++){
        buffer[counter] = map(message[counter]);
    }
    buffer[counter] = '\0';

    cout << "Output buffer with case converted: " << buffer << endl;

    cout << "*************Assignment 4**************" << endl;
    cout << "Assignment 4a" << endl;

    char first;
    int second;
    double third;

    cout << "value of uninitialized char: " << first << endl;
    cout << "value of uninitialized int: " << second << endl;
    cout << "value of uninitialized double: " << third << endl;

    cout << "Assignment 4b" << endl;
    int hundred[100];

    cout << "value of uninitialized 100 integers" << endl;
    for(int i=0; i < 100; i++){
        cout << hundred[i] <<", ";
    }
    cout << endl;

    cout << "*************Assignment 5**************" << endl;

    // Pseudocode from wikipedia:
    //Input: an integer n > 1

    // Let A be an array of Boolean values, indexed by integers 2 to n,
    // initially all set to true.

    //  for i = 2, 3, 4, ..., not exceeding √n:
    //   if A[i] is true:
    //     for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
    //       A[j] := false

    // Output: all i such that A[i] is true.
    int numbers[100];
    char arr[100];
    int n = 100;
    for(int i = 0; i<n; i++){
        numbers[i] = i+1;
        cout << numbers[i] << ", ";
        arr[i] = 't'; // t representing true values in the array
    }
    cout << endl;


    for(int i = 2; i<sqrt(n); i++){
        if(arr[i] == 't'){
            for(int j = i*i; j < n;  j = j+i){
                arr[j] = 'f';
            }
        }
    }

    cout << "the prime numbers are: ";
    for(int i = 2; i<n; i++){
        if(arr[i] == 't'){
            cout << i << ",";
        }
    }
    cout << endl;
}
