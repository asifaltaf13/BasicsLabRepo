#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Listing 1" << std::endl;
    char res = 0;
    for( int c = 0; c < 1000; ++ c ) {
        res = res + 1;
    }
    cout << (int) res << std::endl;


    std::cout << "Listing 2" << std::endl;
    int res2 = 0;
    for(unsigned char c=100; c>=0; --c) {
        res2 = res2 + 1;
    }
    cout << (int) res2 << std::endl;

    return 0;
}