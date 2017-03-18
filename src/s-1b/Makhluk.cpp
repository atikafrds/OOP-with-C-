// NIM/Nama pengembang	: 13514007/Sri Umay N. S.
// Nama file			: Makhluk.cpp

#include "Makhluk.h"

Makhluk::Makhluk() {
	//KOSONG
}

Makhluk::Makhluk(const Makhluk& M) {
	setID(M.id);
	setAge(M.age);
	setStrength(M.strength);
	setPosition(M.position);
}

Makhluk::~Makhluk() {
	//KOSONG
}

Makhluk& Makhluk::operator=(const Makhluk& M) {
	setID(M.id);
	setAge(M.age);
	setStrength(M.strength);
	setPosition(M.position);
	return *this;
}


//GETTER
char Makhluk::getID() {
	return id;
}

int Makhluk::getAge() {
	return age;
}

int Makhluk::getStrength() {
	return strength;
}

Point Makhluk::getPosition() {
	return position;
}

int Makhluk::getSpeed() {return 0;}
int Makhluk::getDirection() {return 0;}


//SETTER
void Makhluk::setID(char _id) {
	id = _id;
}

void Makhluk::setAge(int _age) {
	age = _age;
}

void Makhluk::setStrength(int _strength) {
	strength = _strength;
}

void Makhluk::setPosition(int x, int y) {
	position.setXY(x,y);
}

void Makhluk::setPosition(Point _position) {
	position = _position;
}

void Makhluk::setSpeed(int) {}
void Makhluk::setDirection(int) {}


//FUNGSI LAIN
void Makhluk::update() {
	setAge(getAge()-1);
}