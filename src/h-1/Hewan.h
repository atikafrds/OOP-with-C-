// NIM/Nama pemngembang : 13514054/Muhammad Kamal Nadjieb
// Nama file			: Hewan.h


#ifndef _HEWAN_H
#define _HEWAN_H

#include "Makhluk.h"

class Hewan: public Makhluk {
public:
	Hewan();
	Hewan(const Hewan&);
	virtual ~Hewan();
	Hewan& operator=(const Hewan&);

	//GETTER
	int getSpeed();
	int getDirection();

	//SETTER
	void setSpeed(int);
	void setDirection(int);

	//FUNGSI LAIN
	void update();
protected:
	int speed;
	int direction;
};

#endif