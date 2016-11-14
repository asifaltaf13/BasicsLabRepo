#include <iostream>
#include <math.h>

using namespace std;

struct Vector3 {
    double x;
    double y;
    double z;

    Vector3(double x = 0.0, double y = 0.0, double z = 0.0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

void print(const Vector3 &a)
{
    cout << "x: " << a.x << ", y: " << a.y << ", z: " << a.z << endl;
}

Vector3 add(const Vector3 &a, const Vector3 &b)
{
    Vector3 result;
    result.x = a.x + b.x, result.y = a.y + b.y, result.z = a.z + b.z;
    return result;
}

Vector3 substract(const Vector3 &a, const Vector3 &b)
{
    Vector3 result;
    result.x = a.x - b.x, result.y = a.y - b.y, result.z = a.z - b.z;
    return result;
}

Vector3 multiply(double s, const Vector3 &b)
{
    Vector3 result;
    result.x = s * b.x, result.y = s * b.y, result.z = s * b.z;
    return result;
}

double dot_product(const Vector3 &a, const Vector3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double length(const Vector3 &a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vector3 normalize(const Vector3 &a)
{
    Vector3 result;
    double len = length(a);
    result.x = a.x / len, result.y = a.y / len, result.z = a.z / len;
    return result;
}

Vector3 cross_product(const Vector3 &a, const Vector3 &b)
{
    Vector3 result;
    result.x = a.y * b.z - a.z * b.y
            , result.y = a.z * b.x - a.x * b.z
            , result.z = a.x * b.y - a.y * b.x;
    return result;
}


class Line {

private:
    Vector3 point1, point2;

public:
    Line(const Vector3 &p1, const Vector3 &p2)
    {
        this->point1 = p1;
        this->point2 = p2;
    }

    const Vector3 &get_point1() const
    {
        return point1;
    }

    const Vector3 &get_point2() const
    {
        return point2;
    }

    double distance_to(const Vector3 &p)
    {
        return length(cross_product(substract(p, point1), substract(p, point2))) / length(substract(point2, point1));
    }
};


class Plane {

private:
    Vector3 point, normal;

public:
    Plane(Vector3 p1, Vector3 p2, Vector3 p3)
    {
        normal = multiply(1.0 / length(cross_product(substract(p1, p3), substract(p2, p3))),
                                    cross_product(substract(p1, p3), substract(p2, p3)));
        this->point = p1;
    }

    const Vector3 &get_point()
    {
        return point;
    }

    const Vector3 &get_normal()
    {
        return normal;
    }

    double get_hnf_d()
    {
        return -dot_product(point, normal);
    }

    Vector3 closest_point(const Vector3 &p)
    {
        return substract(p, multiply(get_hnf_d() + dot_product(p, normal), normal));
    }

    double distance_to(const Vector3 &p)
    {
        return dot_product(normal, substract(p, point));
    }

    Vector3 intersect_line(const Line &l)
    {
        Vector3 temp = multiply((get_hnf_d() + dot_product(l.get_point1(), normal)) /
                                (dot_product(normal, substract(l.get_point2(), l.get_point1()))),
                                substract(l.get_point2(), l.get_point1()));

        return substract(l.get_point1(), temp);
    }
};


// Main function
int main()
{
    cout << endl << "___QUESTION#1___" << endl;

    double s = -2.0;

    Vector3 a;
    a.x = 1.0, a.y = 2.0, a.z = 3.0;

    Vector3 b;
    b.x = -1.0, b.y = 2.0, b.z = -2.0;

    cout << endl << "print():" << endl;
    print(a);

    cout << endl << "add():" << endl;
    print(add(a, b));

    cout << endl << "subtract():" << endl;
    print(substract(a, b));

    cout << endl << "subtract():" << endl;
    print(multiply(s, b));

    cout << endl << "Dot product: " << dot_product(a, b) << endl;

    cout << endl << "Length of a: " << length(a) << endl;

    cout << endl << "normalize():" << endl;
    print(normalize(a));

    cout << endl << "cross_product():" << endl;
    print(cross_product(a, b));


    cout << endl << endl << "___QUESTION#3___" << endl << endl;


    Vector3 o(0.0, 0.0, 0.0),
            p1(sqrt(1.0 / 8.0), sqrt(1.0 / 8.0), sqrt(3.0 / 4.0)),
            p2(0.0, 2.0 * sqrt(1.0 / 8.0), 0.0),
            p3(sqrt(1.0 / 8.0) + sqrt(3.0 / 8.0), sqrt(1.0 / 8.0) + sqrt(3.0 / 8.0), sqrt(3.0 / 4.0) - sqrt(1.0 / 4.0)),
            q1(1.0, 1.0, 1.0),
            q2(-1.0, -1.0, 1.0);

    Plane plane(p1, p2, p3);
    print(plane.get_normal());

    cout << "A: " << endl;
    cout << "Plane distance to p1: " << plane.distance_to(p1) << endl;
    cout << "Plane distance to p2: " << plane.distance_to(p2) << endl;
    cout << "Plane distance to p3: " << plane.distance_to(p3) << endl;
    cout << "Plane distance to (p1+p2+p3) / 3: " << plane.distance_to(multiply(1.0 / 3.0, add(p3, add(p1, p2)))) << endl;
    cout << "Plane distance to p1+p2+p3: " << plane.distance_to(add(p3, add(p1, p2))) << endl;

    cout << endl << "B: " << endl;
    cout << "Distance to origin: " << plane.get_hnf_d() << endl;

    cout << endl << "C: " << endl;
    cout << "Distance to origin: " << plane.distance_to(o) << endl;

    cout << endl << "D: " << endl;
    cout << "Closest point to origin: " << endl;
    print(plane.closest_point(o));
    cout << "Distance of point to the origin: " << length(plane.closest_point(o)) << endl;

    cout << endl << "E: " << endl;
    // tangent is a plane that touches a curved surface but does not intersect it
    cout << "The sphere with center origin and radius " << length(plane.closest_point(o))
         << " has the plane as the tangent." << endl;

    Line line(q1, q2);

    cout << endl << "F: " << endl;
    cout << "Distance to point p1 :" << line.distance_to(p1) << endl;
    cout << "Distance to point p2 :" << line.distance_to(p2) << endl;
    cout << "Distance to point p3 :" << line.distance_to(p3) << endl;

    cout << endl << "G: " << endl;
    cout << "Intersection point : " << endl;
    print(plane.intersect_line(line));
    cout << "Distance to plane: " << plane.distance_to(plane.intersect_line(line)) << endl;
    cout << "Distance to line: " << line.distance_to(plane.intersect_line(line)) << endl;

    return 0;
}