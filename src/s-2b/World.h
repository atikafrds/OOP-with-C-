// NIM/Nama pengembang	: 13514009, 13514054/Atika Firdaus, M. Kamal Nadjieb
// Nama file			: World.h

#ifndef _WORLD_H
#define _WORLD_H
#include <iostream>
using namespace std;

#include "ListOfMakhlukSTL.h"

class World {
public:
	World();
	World(int, int, int);
	World(const World&);
	~World();

	//GETTER
	ListOfMakhlukSTL* getLOM();
	int getXMem(int);
	int getYMem(int);
	Point getPositionMem(int);
	char getIDMem(int);
	int getStrengthMem(int);
	int getSpeedMem(int);
	int getDirectionMem(int);
	int getRow();
	int getColumn();
	char getCellElmt(int, int);

	//SETTER
	void setPositionMem(int, int, int);
	void setDirectionMem(int, int);
	void setRow(int);
	void setColumn(int);
	void setCellSize();
	void setCellElmt(int, int, char);
	void setLOM(int);
	void add(Makhluk*);

	//FUNGSI LAIN
	bool isLOMEmpty();
	void move(int);
	void undoMove(int);
	void update();
	void print();

private:
	char** cell;
	int row;
	int column;
	ListOfMakhlukSTL* LOM;
};

#endif