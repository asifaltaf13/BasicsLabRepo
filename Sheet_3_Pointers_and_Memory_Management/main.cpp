#include <iostream>


void callByValue(int value) {
    value = 5;
}
void callByReference(int& reference) {
    reference = 10;
}
void callByPointer(int* pointer) {
    *pointer = 20;
}

int main()
{

    double number = 10.0;
    double number2= 11.0;
    double& reference(number); // reference to variable number
    double* pointer(&number); // pointer to variable number
    std::cout << &number << "; " << &reference << "; " << pointer << std::endl;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    *pointer = 15;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    reference = 50;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    number = 10;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;

    reference = number2;

    std::cout << reference <<std::endl;


    int value = 0;
    callByValue(value);
    std::cout << value << std::endl;
    callByReference(value);
    std::cout << value << std::endl;
    callByPointer(&value);
    std::cout << value << std::endl;

    std::cout << std::endl;

    double array[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 }; // array with five values is initialized
    double* begin = array; // begin pointer starts pointing to head of the array

    std::cout << *(begin + 0) << std::endl; // first item is printed
    std::cout << *(begin + 1) << std::endl; // second item is printed
    std::cout << *(begin + 2) << std::endl; // third item is printed

    double* end = array + 5; // address where 6th item could have been is assigned to end pointer

    int diff = end - begin; //  integer diff stores the difference of end and begin variable locations (which is 5)
    diff /= 2; // 5/2 comes out to be 2

    double value2 = *(begin + 1) + *(end - (diff)); // 20 + 40 = 60 ... 20 is second element, 40 comes if we subtract
    // diff number of location from the sixth element's address

    std::cout << value2 << std::endl; // 60 is printed
    std::cout << *end << std::endl; // address of 6th element (which was initially not the part of the array and hence
    // contains garbage value) is printed

    std::cout << std::endl;
    std::cout << std::endl;

    double* ptr = begin;    // ptr pointer starts pointing to where begin points which is the start of the array
    while (ptr != end) {    // this while loop runs until ptr starts pointing to where end pointer is pointing
        std::cout << *(ptr ++) << " ";
    }
    std::cout << std::endl; // adding a new line
    ptr = end;              // ptr points to the place where end points (which is one after the last element of array)
    while (ptr != begin) {  // this while loop breaks when the ptr points to where begin is pointing
        std::cout << *(-- ptr) << " ";  // this cout decreases the pointer value before cout runs
    } ;
    std::cout << std::endl; // adding a new line


    std::cout << std::endl;
    std::cout << std::endl;


    for(const double* ptr=end-1; ptr != begin; )  // 
    {
        std::cout << *(-- ptr) << " ";
    }

    std::cout << std::endl;

    for(const double* ptr=end-1; ptr != begin; --ptr)
    {
        std::cout << *ptr << " ";
    }

    std::cout << std::endl;

    for(const double* ptr=end-1; ptr >= begin; --ptr)
    {
        std::cout << *ptr << " ";
    }


    return 0;
}