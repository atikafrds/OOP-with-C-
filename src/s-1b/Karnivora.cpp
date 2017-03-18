// NIM/Nama pengembang	: 13514054/M. Kamal Nadjieb
// Nama file			: Karnivora.cpp

#include "Karnivora.h"

Karnivora::Karnivora() {
	inisialisasi();
	setPosition(0,0);
}

Karnivora::Karnivora(int x, int y) {
	inisialisasi();
	setPosition(x,y);
}

Karnivora::Karnivora(Point _position) {
	inisialisasi();
	setPosition(_position);
}

void Karnivora::inisialisasi() {
	srand(time(NULL));
	setID('K');
	setAge(21 + (rand() % 5));
	setStrength(3);
	setSpeed(2);
	int temp = 1;
	for (int i = 1; i <= (1 + (rand() % 2)); ++i) {
		temp = -temp;
	}
	setDirection(temp * (1 + (rand() % 4)));	
}

Karnivora::Karnivora(const Karnivora& H): Hewan(H) {
	//KOSONG
}

Karnivora::~Karnivora() {
	//KOSONG
}

Karnivora& Karnivora::operator=(const Karnivora& H) {
	Hewan::operator= (H);
	return *this;
}