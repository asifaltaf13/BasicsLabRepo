#include <iostream>
#include <typeinfo>

using namespace std;

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

    void push_back(double d)            //adds a new element to the array // O(n)
    {
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


int main(int argc, char **argv)
{
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
        cout<< "\tpress z to exit";
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

    return 0;
}
