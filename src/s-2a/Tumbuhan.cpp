// NIM/Nama pengembang	: 13514007/Sri Umay N. S.
// Nama file			: Tumbuhan.cpp

#include "Tumbuhan.h"

Tumbuhan::Tumbuhan() {
	inisialisasi();
	setPosition(0,0);
}

Tumbuhan::Tumbuhan(int x, int y) {
	inisialisasi();
	setPosition(x,y);
}

Tumbuhan::Tumbuhan(Point _position) {
	inisialisasi();
	setPosition(_position);
}

void Tumbuhan::inisialisasi() {
	srand(time(NULL));
	setID('T');
	setAge(31 + (rand() % 5));
	setStrength(1);
}

Tumbuhan::Tumbuhan(const Tumbuhan& T): Makhluk(T) {
	//KOSONG
}

Tumbuhan::~Tumbuhan() {
	//KOSONG
}

Tumbuhan& Tumbuhan::operator=(const Tumbuhan& T) {
	Makhluk::operator= (T);
	return *this;
}