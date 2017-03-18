#include "ListOfMakhluk.h"
#include <iostream>
using namespace std;

int main() {
	ListOfMakhluk L(10);
	Herbivora* H = new Herbivora();
	Omnivora* O = new Omnivora();
	L.add(H);
	L.add(O);
	cout << "NMax = " << L.getNMax() << endl;
	cout << "NEff = " << L.getNEff() << endl;
	Makhluk** arrMakhluk;
	arrMakhluk = L.getAllMem();
	for (int i = 0; i < L.getNEff(); ++i) {
		cout << "ID: " << L.getMem(i)->getID() << endl;
		cout << "Age: " << L.getMem(i)->getAge() << endl;
	}
	L.update();
	for (int i = 0; i < L.getNEff(); ++i) {
		cout << "ID: " << L.getMem(i)->getID() << endl;
		cout << "Age: " << L.getMem(i)->getAge() << endl;
	}
	L.remove(0);
	for (int i = 0; i < L.getNEff(); ++i) {
		cout << "ID: " << L.getMem(i)->getID() << endl;
		cout << "Age: " << L.getMem(i)->getAge() << endl;
	}

	return 0;
}