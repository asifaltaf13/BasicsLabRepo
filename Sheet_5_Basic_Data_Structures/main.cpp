#include <iostream>
#include <string.h>

using namespace std;

// Question 1

class DynamicDoubleArray
{
    private:

    double *elements;
    int size;

    public:

    DynamicDoubleArray(int size = 0)        // linear complexity
    {
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

    int get_size()                      //get the number of elements stored inside the array // constant time
    {
        return size;
    }

    double &at(int idx)                 // access the element positioned at idx // constant time
    {
        return elements[idx];
    }

    void push_back(double d)            // adds a new element to the array // O(n)
    {                                   // we can improve it if we have a dynamic structure, array are not dynamic, they have fixed size
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

    void remove(int idx)                // remove the element at idx from the array // O(n)
    {
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

    void clear()                        // delete all the data store inside the array // constant
    {
        delete[] elements;
        size = 0;
    }

    void printArray()                   // prints the entire array // O(n)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "DynamicDoubleArray[" << i << "] = " << elements[i] << endl;
        }
    }


};

// Question 2

// Part A
void bubbleSortIndices(double* data, int size)
{
    double temp;
    for(int i = 0; i<size; i++) //loop to get an element to compare with others
    {
        for(int j = 0; j<size - 1 - i; j++) // comparing loop, compare 1 element with all other
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

// Part B
void  bubbleSortPointer(double* data, int size)
{
    double temp;
    for(int i = 0; i<size; i++) //loop to get an element to compare with others
    {
        for(int j = 0; j<size - 1 - i; j++) // comparing loop, compare 1 element with all other
        {
            if(*(data + j) > *(data + j + 1))   // it works because the data is a pointer to an array
            {                                   // and its elements can also be accessed by using dereference operator and adding an offset
                temp = *(data + j);
                *(data + j) = *(data + j + 1);
                *(data + j + 1) = temp;
            }
        }
    }
}

// Part C
void joinSorted(double* left, int sizeLeft, double* right, int sizeRight, double* output)
{
    int i, j=0, k=0;
    for(i=0; i<sizeRight+sizeLeft; i++)
    {
        if(j==sizeLeft)                         //When array L is empty
        {
            *(output+i) = *(right+k);           // add the element from array R
            k++;
        }
        else if(k==sizeRight)                   //When array R is empty
        {
            *(output+i) = *(left+j);            // add the element from array L
            j++;
        }
        else if(*(left+j) < *(right+k))         //When element in L is smaller than element in R
        {
            *(output+i) = *(left+j);            // add the element from array L
            j++;
        }
        else                                    //When element in R is smaller or equal to element in L
        {
            *(output+i) = *(right+k);
            k++;
        }
    }
}

// Part D
void mergeSort(double *data, int size)
{
    int i;

    if(size > 1)
    {
        int sizeLeft = size/2 + size%2;                     //length of first array
        int sizeRight = size/2;                             //length of second array

        double left[sizeLeft];                              //left array
        double right[sizeRight];                            //right array

        for(i=0; i<sizeLeft; i++)
        {
            left[i] = *(data+i);                            //inserting elements in left array
        }

        for(i=0; i<sizeRight; i++)
        {
            right[i] = *(data+sizeLeft+i);                  //inserting elements in right array
        }

        mergeSort(left, sizeLeft);
        mergeSort(right, sizeRight);

        joinSorted(left, sizeLeft, right, sizeRight, data); //Merge arrays left and right into data
    }
    else
    {
        return;                                             //if array only have one element just return
    }
}

// main function
int main(int argc, char **argv)
{
    //Question 1
    cout<< "\n\n___Question#1___\n\n";

    int size;

    DynamicDoubleArray array;

    char check = 'a';

    while (check != 'z')
    {
        cout<< "\nMenu Options:\n";
        cout<< "\tpress a to add an element to the array\n";
        cout<< "\tpress c to clear the array\n";
        cout<< "\tpress p to print the array\n";
        cout<< "\tpress r to remove an element from the array\n";
        cout<< "\tpress s to print the size of the array\n";
        cout<< "\tpress z to exit question#1";
        cout<< endl << endl;

        cout<<"\nEnter your selection: ";
        cin >> check;

        switch (check)
        {
            case 'a':
                double value;
                cout << "Enter a numerical value to add to the array: " << flush;
                cin >> value;
                array.push_back(value);
                break;

            case 'p':
                array.printArray();
                break;

            case 'c':
                array.clear();
                break;

            case 's':
                cout << "Size of the array is: "<< array.get_size() << endl;
                break;

            case 'r':
                int index;
                cout << "Enter index of the element to remove: " << endl;
                cin >> index;
                array.remove(index);
                break;

            case 'z':
                break;
        }

        cout << "\nSize of the array is: "<< array.get_size() << endl;
    }

    //Question 2
    cout<< "\n\n___Question#2___\n\n";

    cout << "Please enter the size of data elements that you want to sort: ";
    cin >> size;

    double data_indices[size];
    double data_pointer[size];
    double data_mergesort[size];

    cout << "Please enter the data" << endl;

    for(int i = 0; i < size; i++)   // assigning values
    {
        cin >> data_indices[i];
        data_pointer[i] = data_indices[i];
        data_mergesort[i] = data_indices[i];
    }

    // Part A
    bubbleSortIndices(data_indices, size);
    cout << "The sorted data using bubble sort indices is: " << endl;
    for(int i =0; i < size; i++)
    {
        cout << data_indices[i] << ", " ;
    }
    cout << endl;

    // Part B
    bubbleSortPointer(data_pointer, size);
    cout << "The sorted data using bubble sort pointer is: " << endl;
    for(int i =0; i < size; i++)
    {
        cout << data_pointer[i] << ", " ;
    }
    cout << endl;

    // Part D
    mergeSort(data_mergesort, size);
    cout << "The sorted data using merge sort is: " << endl;
    for(int i =0; i < size; i++)
    {
        cout << data_mergesort[i] << ", " ;
    }
    cout << endl;

    return 0;
}

// bubble sort complexity
//  runtime complexities: best case O(n), worst O(n^2), average O(n^2)
//  space complexity: O(1)

// merge sort
// runtime complexities: best O(n lg n), worst O(n), average O(n lg n)
// space complexity: O(n)
