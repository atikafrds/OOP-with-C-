#include "Omnivora.h"

#include <iostream>
using namespace std;

int main() {
	Omnivora O1;
	cout << O1.getAge() << endl;
	cout << O1.getDirection() << endl;
	cout << O1.getPosition().getX() << ' ' << O1.getPosition().getY() << endl;
	O1.update();
	cout << O1.getAge() << endl;
	cout << O1.getPosition().getY() << ' ' << O1.getPosition().getY() << endl;
	
    return 0;
}