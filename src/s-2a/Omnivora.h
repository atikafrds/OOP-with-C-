// NIM/Nama pengembang	: 13514054/M. Kamal Nadjieb
// Nama file			: Omnivora.h

#ifndef _OMNIVORA_H
#define _OMNIVORA_H

#include "Hewan.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class Omnivora: public Hewan {
public:
	Omnivora();
	Omnivora(int, int);
	Omnivora(Point);
	Omnivora(const Omnivora&);
	~Omnivora();
	Omnivora& operator=(const Omnivora&);

	//GETTER

	//SETTER
private:
	void inisialisasi();
};

#endif