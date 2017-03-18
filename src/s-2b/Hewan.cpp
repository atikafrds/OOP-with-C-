// NIM/Nama pengembang	: 13514054/M. Kamal Nadjieb
// Nama file			: Hewan.cpp

#include "Hewan.h"

#include <iostream>
using namespace std;

Hewan::Hewan() {
	//KOSONG
}

Hewan::Hewan(const Hewan& H): Makhluk(H) {
	setSpeed(H.speed);
	setDirection(H.direction);
}

Hewan::~Hewan() {
	//KOSONG
}

Hewan& Hewan::operator=(const Hewan& H) {
	Makhluk::operator= (H);
	setSpeed(H.speed);
	setDirection(H.direction);
	return *this;
}


//GETTER
int Hewan::getSpeed() {
	return speed;
}

int Hewan::getDirection() {
	return direction;
}


//SETTER
void Hewan::setSpeed(int _speed) {
	speed = _speed;
}

void Hewan::setDirection(int _direction) {
	direction = _direction;
}

//FUNGSI LAIN
void Hewan::update() {
	setAge(getAge()-1);
	/*
		-2	 1	2
		-3		3
		-4	-1	4
	*/
	Point P = getPosition();
	switch (getDirection()) {
		case 1:
			P.move(0,-speed);
			break;
		case 2:
			P.move(speed,-speed);
			break;
		case 3:
			P.move(speed,0);
			break;
		case 4:
			P.move(speed,speed);
			break;
		case -1:
			P.move(0,speed);
			break;
		case -2:
			P.move(-speed,-speed);
			break;
		case -3:
			P.move(-speed,0);
			break;
		case -4:
			P.move(-speed,speed);
			break;
	}
	setPosition(P);
}