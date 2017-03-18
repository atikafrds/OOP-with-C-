// NIM/Nama pemngembang : 13514009/Atika Firdaus
// Nama file			: ListOfMakhlukSTL.h


#ifndef _LOM_H
#define _LOM_H

#include <vector>
#include <thread>
#include "Tumbuhan.h"
#include "Herbivora.h"
#include "Karnivora.h"
#include "Omnivora.h"

class ListOfMakhlukSTL {
public:
	ListOfMakhlukSTL();
	ListOfMakhlukSTL(int);
	ListOfMakhlukSTL(const ListOfMakhlukSTL&);
	~ListOfMakhlukSTL();
	ListOfMakhlukSTL& operator=(const ListOfMakhlukSTL&);

	//GETTER
	vector<Makhluk*> getAllMem();
	Makhluk* getMem(int);
	int getNMax();
	int getNEff();

	//SETTER
	void setMem(int, Makhluk*);
	void setNMax(int);

	//FUNGSI LAIN
	void add(Makhluk*);
	void remove(int);
	void update();
	void process(int);
	
private:
	const static int deltaMem;
	vector<Makhluk*> mem;
	int nMax;
};

#endif