// NIM/Nama pemngembang : 13514054/Muhammad Kamal Nadjieb
// Nama file			: ListOfMakhluk.h

#ifndef _LOM_H
#define _LOM_H

#include "Tumbuhan.h"
#include "Herbivora.h"
#include "Karnivora.h"
#include "Omnivora.h"

class ListOfMakhluk {
public:
	ListOfMakhluk();
	ListOfMakhluk(int);
	ListOfMakhluk(const ListOfMakhluk&);
	~ListOfMakhluk();
	ListOfMakhluk& operator=(const ListOfMakhluk&);

	//GETTER
	Makhluk** getAllMem();
	Makhluk* getMem(int);
	int getNMax();
	int getNEff();

	//SETTER
	void setMem(int, Makhluk*);
	void setNMax(int);
	void setNEff(int);

	//FUNGSI LAIN
	void add(Makhluk*);
	void remove(int);
	void compress();
	void update();
private:
	const static int deltaMem;
	Makhluk** mem;
	int nMax;
	int nEff;
};

#endif