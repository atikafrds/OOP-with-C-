#include "Point.h"

#include <iostream>
using namespace std;

int main() {
    Point P1;
    Point P2(1,2);
    P1 = P2;
    Point P3 = P1;
    P3.move(1,2);
    cout << P3.getX() << ' ' << P3.getY() << endl;
    return 0;
}