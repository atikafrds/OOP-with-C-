#include "Herbivora.h"
#include <iostream>
using namespace std;

int main() {
	Herbivora H1;
	cout << H1.getAge() << endl;
	cout << H1.getDirection() << endl;
	cout << H1.getPosition().getX() << ' ' << H1.getPosition().getY() << endl;
	H1.update();
	cout << H1.getAge() << endl;
	cout << H1.getPosition().getX() << ' ' << H1.getPosition().getY() << endl;

    return 0;
}