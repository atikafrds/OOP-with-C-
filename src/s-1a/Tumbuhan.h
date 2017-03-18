// NIM/Nama pemngembang : 13514007/Sri Umay Nur'aini Sholihah
// Nama file			: Tumbuhan.h


#ifndef _TUMBUHAN_H
#define _TUMBUHAN_H

#include "Makhluk.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class Tumbuhan: public Makhluk {
public:
	Tumbuhan();
	Tumbuhan(int, int);
	Tumbuhan(Point);
	Tumbuhan(const Tumbuhan&);
	~Tumbuhan();
	Tumbuhan& operator=(const Tumbuhan&);
private:
	void inisialisasi();
};

#endif