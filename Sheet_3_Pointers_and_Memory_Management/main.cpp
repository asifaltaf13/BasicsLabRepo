#include <iostream>
#include <math.h>

using namespace std;


int string_length(const char* string) {
    int length = 0;

    for(const char* ptr = string; *ptr != '\0'; ++ ptr) {
        ++ length;
    }
    return length;
}


char* string_copy(const char* string) {
// we need to add 1 because of ’\0’
    char* result = new char[string_length(string) + 1];

    int i = 0;
    int l = string_length(string);
    for(; i < l ; i++){

        result[i] = string[i];

    }

    result[i] = '\0';

// write your code here (remember zero-termination !)

    return result;
}



float mean(float* arr ,int size){

    float sum = 0.f;

    for(int i = 0 ; i < size ; i++){

        sum += arr[i];

    }

    return sum/(float)size;
}

float variance(float* arr, int size){

    float m = mean(arr, size);

    for(int i = 0 ; i < size ; i++){

        arr[i] = pow(arr[i]-m, 2);

    }

    return mean(arr, size);

}


int main(int argc, char** argv) {

    const char* string_c = "This is a string and is a long one so that we can create memory leaks when it is copied and not deleted";
// write your code here

    char * result = NULL;
    result = string_copy(string_c);

    for(int i = 0 ; i < 1000000 ; i++){

        char *temp = result;
        result = string_copy(result);
        delete [] temp;

        // if we don't delete the temp strings, the program leaks a lot of memory
    }

    cout<<result<<endl;
    delete [] result;


    int count;
    float* arr;

    cout<<"Please enter a count: "<<endl;
    cin>>count;

    arr = new float[count];
    cout<<"Enter the floats and press enter: "<<endl;

    for(int i = 0 ; i < count ; i++){
        cin>>arr[i];
    }

    cout<<"Mean: "<<mean(arr, count)<<endl;
    cout<<"variance: "<<variance(arr, count)<<endl;

    delete [] arr;

    return 0;

}