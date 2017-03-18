// NIM/Nama pemngembang : 13514098/Joshua Atmadja
// Nama file			: Point.cpp


#include "Point.h"

Point::Point() {
	setXY(0,0);
}

Point::Point(int _X, int _Y) {
	setXY(_X, _Y);
}

Point::Point(const Point& P) {
	setXY(P.x,P.y);
}

Point::~Point() {
	//KOSONG
}

Point& Point::operator=(const Point& P) {
	setXY(P.x, P.y);
	return *this;
}


//GETTER
int Point::getX() {
	return x;
}
int Point::getY() {
	return y;
}


//SETTER
void Point::setXY(int X, int Y){
    setX(X);
    setY(Y);
}

void Point::setX(int _X) {
	x = _X;
}

void Point::setY(int _Y) {
	y = _Y;
}

//FUNGSI LAIN
bool Point::operator==(const Point& P) {
	return ((getX() == P.x) && (getY() == P.y));
}

void Point::move(int dx, int dy) {
	setXY(getX()+dx,getY()+dy);
}