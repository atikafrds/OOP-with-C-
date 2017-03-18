// NIM/Nama pemngembang : 13514009/Atika Firdaus
// Nama file			: ListOfMakhlukSTL.cpp


#include "ListOfMakhlukSTL.h"

const int ListOfMakhlukSTL::deltaMem = 10;

ListOfMakhlukSTL::ListOfMakhlukSTL() {
	nMax = deltaMem;
}

ListOfMakhlukSTL::ListOfMakhlukSTL(int _nMax) {
	nMax = _nMax;
}

ListOfMakhlukSTL::ListOfMakhlukSTL(const ListOfMakhlukSTL& LOM) {
	nMax = LOM.nMax;
	for (int i = 0; i < nMax; ++i) {
		mem.push_back(LOM.mem[i]);
	}
}

ListOfMakhlukSTL::~ListOfMakhlukSTL() {

}

ListOfMakhlukSTL& ListOfMakhlukSTL::operator=(const ListOfMakhlukSTL& LOM) {
	nMax = LOM.nMax;
	for (int i = 0; i < nMax; ++i) {
		mem.push_back(LOM.mem[i]);
	}
	return *this;
}


//GETTER
vector<Makhluk*> ListOfMakhlukSTL::getAllMem() {
	return mem;
}

Makhluk* ListOfMakhlukSTL::getMem(int i) {
	return mem[i];
}

int ListOfMakhlukSTL::getNMax() {
	return nMax;
}

int ListOfMakhlukSTL::getNEff() {
	return mem.size();
}


//SETTER
void ListOfMakhlukSTL::setMem(int i, Makhluk* M) {
	mem[i] = M;
}

void ListOfMakhlukSTL::setNMax(int _nMax) {
	nMax = _nMax;
}


//FUNGSI LAIN
void ListOfMakhlukSTL::add(Makhluk* M) {
	if (mem.size() < nMax) {
		mem.push_back(M);
	}
}

void ListOfMakhlukSTL::remove(int i) {
	mem.erase(mem.begin()+i);
}

void ListOfMakhlukSTL::update() {
	// int size = getNEff();
	vector<thread> th;
	for (int i = 0; i < getNEff(); ++i) {
		th.push_back(thread(&ListOfMakhlukSTL::process, this, i));		
	}
	for (int i = 0; i < getNEff(); ++i) {
		th[i].join();
	}
	for (int i = 0; i < getNEff(); ++i) {
		if (mem[i]->getAge() == 0) {
			remove(i);
		}
	}
}

void ListOfMakhlukSTL::process(int i) {
	mem[i]->update();
}