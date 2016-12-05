//
// Created by asif on 05.12.16.
//

#include "assignment5_1.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class DynamicDoubleArray {

private:
    double *elements;
    int size;

public:
    DynamicDoubleArray(int size = 0)
    { // linear complexity
        this->size = size;
        this->elements = new double[size];
    }

    ~DynamicDoubleArray()
    {
        if (size > 0)
        {
            delete[] elements;
        }
    }

    int get_size()
    { //get the number of elements stored inside the array // constant time
        return size;
    }

    double &at(int idx)
    { // access the element positioned at idx // constant time
        return elements[idx];
    }

    void push_back(double d)
    { //adds a new element to the array // O(n)
        double *temp = new double[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = elements[i];
        }

        temp[size] = d;

        if (size > 0)
        {
            delete[] elements;
        }
        size++;
        elements = temp;
    }

    void remove(int idx)
    { // remove the element at idx from the array // O(n)
        if (size > 0)
        {
            double *tempArray = new double[size - 1];
            int i, j;

            for (i = 0, j = 0; i < size; i++)
            {
                if (i != idx)
                {
                    tempArray[j++] = elements[i];
                }
            }

            size--;

            delete[] elements;
            elements = tempArray;
        }
    }

    void clear()
    { // delete all the data store inside the array // constant
        delete[] elements;
        size = 0;
    }

    void printArray()
    { // prints the entire array // O(n)
        for (int i = 0; i < size; i++)
        {
            cout << "DynamicDoubleArray[" << i << "] = " << elements[i] << endl;
        }
    }
};

/*
int main(int argc, char** argv) {
    int size;

    DynamicDoubleArray array;

    char check = 'a';

    while(check != 'z'){

        cout << "Press a to add an element to the array\n p to print the array\n c to clear the array\n r to remove the first element from the array\n z to exit" << endl << endl;
        cin >> check;

        switch(check){
            case 'a':

                double value;
                cout << "Enter value to add to the array: " << flush;
                cin >> value;
                array.push_back(value);
                break;

            case 'p':

                array.printArray();
                break;

            case 'c':

                array.clear();
                break;

            case 'r':

                int index;
                cout << "Enter index to remove element" << endl;
                cin >> index;
                array.remove(index);
                break;

            case 'z':
                break;

        }
    }
    return 0;
}
*/