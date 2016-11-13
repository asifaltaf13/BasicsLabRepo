#include <iostream>
#include <math.h>

using namespace std;

//struct Vector3
//{
//    double x;
//    double y;
//    double z;
//};
//
//void print(const Vector3& a)
//{
//    cout<<"x: " << a.x << ", y: " << a.y << ", z: " << a.z << endl;
//
//}
//
//Vector3 add(const Vector3& a, const Vector3& b)
//{
//    Vector3 result;
//    result.x= a.x+b.x, result.y= a.y+b.y, result.z= a.z+b.z;
//    return result;
//}
//
//Vector3 substract(const Vector3& a, const Vector3& b)
//{
//    Vector3 result;
//    result.x= a.x-b.x, result.y= a.y-b.y, result.z= a.z-b.z;
//    return result;
//}
//
//Vector3 multiply(double s, const Vector3& b)
//{
//    Vector3 result;
//    result.x= s*b.x, result.y= s*b.y, result.z= s*b.z;
//    return result;
//}
//
//double dot_product(const Vector3& a, const Vector3& b)
//{
//    return a.x*b.x + a.y*b.y + a.z*b.z;
//}
//
//double length(const Vector3& a)
//{
//    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
//}
//
//Vector3 normalize(const Vector3& a)
//{
//    Vector3 result;
//    double len = length(a);
//    result.x = a.x/len, result.y = a.y/len, result.z = a.z/len;
//    return result;
//}
//
//Vector3 cross_product(const Vector3& a, const Vector3& b)
//{
//    Vector3 result;
//    result.x = a.y * b.z - a.z * b.y
//            , result.y = a.z * b.x - a.x * b.z
//            , result.z = a.x * b.y - a.y * b.x;
//    return result;
//}
//
//int main(){
//
//	double s = -2.0;
//
//	Vector3 a;
//    a.x = 1.0, a.y = 2.0, a.z = 3.0;
//
//    Vector3 b;
//    b.x = -1.0, b.y = 2.0, b.z = -2.0;
//
//    cout<<endl<<"print():"<<endl;
//	print(a);
//
//    cout<<endl<<"add():"<<endl;
//	print(add(a,b));
//
//    cout<<endl<<"subtract():"<<endl;
//    print(substract(a,b));
//
//    cout<<endl<<"subtract():"<<endl;
//    print(multiply(s,b));
//
//    cout<<endl<< "Dot product: " << dot_product(a,b) << endl;
//
//    cout<<endl<< "Length of a: " << length(a) << endl;
//
//    cout<<endl<<"normalize():"<<endl;
//    print(normalize(a));
//
//    cout<<endl<<"cross_product():"<<endl;
//    print(cross_product(a,b));
//
//	return 0;
//}


class A {
public:
    int counter;
    A(int a = 1) {
        counter = a;
        cout << "construct A: " << counter << endl;
    }
    ~A() {
        cout << "destruct A: " << counter << endl;
    }
    void use() {
        if( -- counter > 0 ) {
            cout << counter << " times left" << endl;
        }
    }
};

int main()
{
    A a1(4), a2(2);     // constructor is called for each of these object creations with values 4 and 2 respectively

    a1.use();           // use is called and "3 times left" is printed
    {
        A a3;           // a3 is created inside this scope and constructor is called for that object with default value 1
        a3.use();       // cout does not run if --counter<=0
        a1.use();       // printed "2 times left"
        a3.use();       // again nothing to print
    }                   // a3's scope ends so destructor is called printing "destuct A: -1"
    a1.use();           // printed "1 times left"
    return 0;
}                       // scope ends for a1 and a2 so they are destroyed