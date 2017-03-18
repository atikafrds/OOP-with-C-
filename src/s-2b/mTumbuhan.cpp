#include "Tumbuhan.h"

#include <iostream>
using namespace std;

int main() {
	Point P(1,2);
	Tumbuhan T1(P);
	Tumbuhan T2(3,4);
	T1 = T2;
	Tumbuhan T3 = T1;

	P = T3.getPosition();
	cout << T3.getID() << endl;
	cout << T3.getAge() << endl;
	cout << T3.getStrength() << endl;
	cout << P.getX() << ' ' << P.getY() << endl;
    return 0;
}