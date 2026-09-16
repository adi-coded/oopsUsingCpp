#include <iostream>
#include <cmath>
using namespace std;

class Point {
    float x;
    float y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(float val) {
        x = val;
        y = val;
    }
    Point(float x_val, float y_val) {
        x = x_val;
        y = y_val;
    }

    void show() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    float distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    float distanceBetween(Point p) {
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }
};

int main() {
 
    Point one;               
    Point two(5.0f);        
    Point three(2.0f, 7.0f);  

    cout << "point 1: "; one.show();
    cout << "point 2: "; two.show();
    cout << "point 3: "; three.show();

    cout << "Distance of point one from origin: " << one.distanceFromOrigin() << endl;
    cout << "Distance of point two from origin: " << two.distanceFromOrigin() << endl;
    cout << "Distance of point three from origin: " << three.distanceFromOrigin() << endl;

    cout << "Distance between point two and three: " << two.distanceBetween(three) << endl;

    return 0;
}

