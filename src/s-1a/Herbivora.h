// NIM/Nama pemngembang : 13514098/Joshua Atmadja
// Nama file			: Herbivora.h


#ifndef _HERBIVORA_H
#define _HERBIVORA_H

#include "Hewan.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class Herbivora: public Hewan {
public:
	Herbivora();
	Herbivora(int, int);
	Herbivora(Point);
	Herbivora(const Herbivora&);
	~Herbivora();
	Herbivora& operator=(const Herbivora&);
private:
	void inisialisasi();
};

#endif