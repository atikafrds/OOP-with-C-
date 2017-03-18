// NIM/Nama pemngembang : 13514054/Muhammad Kamal Nadjieb
// Nama file			: Karnivora.h


#ifndef _KARNIVORA_H
#define _KARNIVORA_H

#include "Hewan.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class Karnivora: public Hewan {
public:
	Karnivora();
	Karnivora(int, int);
	Karnivora(Point);
	Karnivora(const Karnivora&);
	~Karnivora();
	Karnivora& operator=(const Karnivora&);
private:
	void inisialisasi();
};

#endif