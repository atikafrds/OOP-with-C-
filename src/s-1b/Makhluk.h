// NIM/Nama pengembang	: 13514007/Sri Umay N. S.
// Nama file			: Makhluk.h

#ifndef _MAKHLUK_H
#define _MAKHLUK_H

#include "Point.h"

class Makhluk {
public:
	Makhluk();
	Makhluk(const Makhluk&);
	virtual ~Makhluk();
	Makhluk& operator=(const Makhluk&);

	//GETTER
	char getID();
	int getAge();
	int getStrength();
	Point getPosition();
	virtual int getSpeed();
	virtual int getDirection();

	//SETTER
	void setID(char);
	void setAge(int);
	void setStrength(int);
	void setPosition(int, int);
	void setPosition(Point);
	virtual void setSpeed(int);
	virtual void setDirection(int);

	//FUNGSI LAIN
	virtual void update();
protected:
	char id;
	int age;
	int strength;
	Point position;
private:
	virtual void inisialisasi() = 0;
};

#endif