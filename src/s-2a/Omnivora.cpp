// NIM/Nama pengembang	: 13514054/M. Kamal Nadjieb
// Nama file			: Omnivora.cpp

#include "Omnivora.h"

Omnivora::Omnivora() {
	inisialisasi();
	setPosition(0,0);
}

Omnivora::Omnivora(int x, int y) {
	inisialisasi();
	setPosition(x,y);
}

Omnivora::Omnivora(Point _position) {
	inisialisasi();
	setPosition(_position);
}

void Omnivora::inisialisasi() {
	srand(time(NULL));
	setID('O');
	setAge(16 + (rand() % 5));
	setStrength(4);
	setSpeed(1);
	int temp = 1;
	for (int i = 1; i <= (1 + (rand() % 2)); ++i) {
		temp = -temp;
	}
	setDirection(temp * (1 + (rand() % 4)));	
}

Omnivora::Omnivora(const Omnivora& H): Hewan(H) {
	//KOSONG
}

Omnivora::~Omnivora() {
	//KOSONG
}

Omnivora& Omnivora::operator=(const Omnivora& H) {
	Hewan::operator= (H);
	return *this;
}