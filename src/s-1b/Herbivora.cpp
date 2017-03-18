// NIM/Nama pengembang	: 13514098/Joshua Atmadja
// Nama file			: Herbivora.cpp


#include "Herbivora.h"

Herbivora::Herbivora() {
	inisialisasi();
	setPosition(0,0);
}

Herbivora::Herbivora(int x, int y) {
	inisialisasi();
	setPosition(x,y);
}

Herbivora::Herbivora(Point _position) {
	inisialisasi();
	setPosition(_position);
}

void Herbivora::inisialisasi() {
	srand(time(NULL));
	setID('H');
	setAge(26 + (rand() % 5));
	setStrength(2);
	setSpeed(3);
	int temp = 1;
	for (int i = 1; i <= (1 + (rand() % 2)); ++i) {
		temp = -temp;
	}
	setDirection(temp * (1 + (rand() % 4)));	
}

Herbivora::Herbivora(const Herbivora& H): Hewan(H) {
	//KOSONG
}

Herbivora::~Herbivora() {
	//KOSONG
}

Herbivora& Herbivora::operator=(const Herbivora& H) {
	Hewan::operator= (H);
	return *this;
}