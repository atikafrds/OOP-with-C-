#include "Karnivora.h"

#include <iostream>
using namespace std;

int main() {
	Karnivora K1;
	cout << K1.getAge() << endl;
	cout << K1.getDirection() << endl;
	cout << K1.getPosition().getX() << ' ' << K1.getPosition().getY() << endl;
	K1.update();
	cout << K1.getAge() << endl;
	cout << K1.getPosition().getY() << ' ' << K1.getPosition().getY() << endl;
    return 0;
}