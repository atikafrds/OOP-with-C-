// NIM/Nama pengembang	: 13514054/M. Kamal Nadjieb
// Nama file			: ListOfMakhluk.cpp

#include "ListOfMakhluk.h"

const int ListOfMakhluk::deltaMem = 10;

ListOfMakhluk::ListOfMakhluk() {
	nMax = deltaMem;
	nEff = 0;
	mem = new Makhluk*[nMax];
}

ListOfMakhluk::ListOfMakhluk(int _nMax) {
	nMax = _nMax;
	nEff = 0;
	mem = new Makhluk*[nMax];
}

ListOfMakhluk::ListOfMakhluk(const ListOfMakhluk& LOM) {
	nMax = LOM.nMax;
	nEff = LOM.nEff;
	mem = new Makhluk*[nMax];
	for (int i = 0; i < nMax; ++i) {
		mem[i] = LOM.mem[i];
	}
}

ListOfMakhluk::~ListOfMakhluk() {
	delete [] mem;
}

ListOfMakhluk& ListOfMakhluk::operator=(const ListOfMakhluk& LOM) {
	nMax = LOM.nMax;
	nEff = LOM.nEff;
	mem = new Makhluk*[nMax];
	for (int i = 0; i < nMax; ++i) {
		mem[i] = LOM.mem[i];
	}
	return *this;
}


//GETTER
Makhluk** ListOfMakhluk::getAllMem() {
	return mem;
}

Makhluk* ListOfMakhluk::getMem(int i) {
	return mem[i];
}

int ListOfMakhluk::getNMax() {
	return nMax;
}

int ListOfMakhluk::getNEff() {
	return nEff;
}


//SETTER
void ListOfMakhluk::setMem(int i, Makhluk* M) {
	mem[i] = M;
}

void ListOfMakhluk::setNMax(int _nMax) {
	nMax = _nMax;
}

void ListOfMakhluk::setNEff(int _nEff) {
	nEff = _nEff;
}


//FUNGSI LAIN
void ListOfMakhluk::add(Makhluk* M) {
	if (nEff == nMax) {
		Makhluk** _mem = new Makhluk*[nMax];
		for (int i = 0; i < nMax; ++i) {
			_mem[i] = mem[i];
		}
		delete [] mem;
		nMax += deltaMem;
		mem = new Makhluk*[nMax];
		for (int i = 0; i < nMax; ++i) {
			mem[i] = _mem[i];
		}
		delete [] _mem;
	}

	mem[nEff] = M;
	++nEff;
}

void ListOfMakhluk::remove(int i) {
	delete mem[i];
	while (i < nEff) {
		mem[i] = mem[i+1];
		++i;
	}
	mem[i] = NULL;
	--nEff;
}

void ListOfMakhluk::compress() {
	if ((nMax-nEff == deltaMem) && (nEff != 0)) {
		Makhluk** _mem = new Makhluk*[nMax];
		for (int i = 0; i < nMax; ++i) {
			_mem[i] = mem[i];
		}
		delete [] mem;
		nMax -= deltaMem;
		mem = new Makhluk*[nMax];
		for (int i = 0; i < nMax; ++i) {
			mem[i] = _mem[i];
		}
		delete [] _mem;
	}
}

void ListOfMakhluk::update() {
	for (int i = 0; i < nEff; ++i) {
		mem[i]->update();
		if (mem[i]->getAge() == 0) {
			remove(i);
		}
	}
}