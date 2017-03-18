// NIM/Nama pemngembang : 13514098/Joshua Atmadja
// Nama file			: Point.h


#ifndef _POINT_H
#define _POINT_H

#include <iostream>
using namespace std;

class Point {
public:
	Point ();
	Point (int _X, int _Y);
	Point (const Point&);
	~Point ();
	Point& operator= (const Point&);

	//GETTER
	int getX();
	int getY();

	//SETTER
	void setXY(int, int);
	void setX(int);
	void setY(int);

	//FUNGSI LAIN
	bool operator==(const Point&);
	void move (int, int);

private:
	int x;
	int y;
};

#endif