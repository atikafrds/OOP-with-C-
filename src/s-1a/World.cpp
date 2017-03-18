#include "World.h"

World::World() {
	setRow(7);
	setColumn(5);
	setCellSize();
	setLOM(10);
}

World::World(int _row, int _column, int _nMax) {
	setRow(_row);
	setColumn(_column);
	setCellSize();
	setLOM(_nMax);
}

World::World(const World& W) {
	setRow(W.row);
	setColumn(W.column);
	cell = new char*[getColumn()];
	for (int i = 0; i < getColumn(); ++i) {
		cell[i] = new char[getRow()];
		for (int j = 0; j < getRow(); ++j) {
			setCellElmt(i,j,W.cell[i][j]);
		}
	}
	setLOM(W.LOM->getNMax());
	LOM = W.LOM;
}

World::~World() {
	for (int i = 0; i < getColumn(); ++i) {
		delete[] cell[i];
	}
	delete [] cell;
	delete LOM;
}


//GETTER
ListOfMakhluk* World::getLOM() {
	return LOM;
}

int World::getXMem(int i) {
	return LOM->getMem(i)->getPosition().getX();
}

int World::getYMem(int i) {
	return LOM->getMem(i)->getPosition().getY();
}

Point World::getPositionMem(int i) {
	return LOM->getMem(i)->getPosition();
}

char World::getIDMem(int i) {
	return LOM->getMem(i)->getID();
}

int World::getStrengthMem(int i) {
	return LOM->getMem(i)->getStrength();
}

int World::getSpeedMem(int i) {
	return LOM->getMem(i)->getSpeed();
}

int World::getDirectionMem(int i) {
	return LOM->getMem(i)->getDirection();
}

int World::getRow() {
	return row;
}

int World::getColumn() {
	return column;
}

char World::getCellElmt(int i, int j) {
	return cell[i][j];
}


//SETTER
void World::setPositionMem(int i, int x, int y) {
	LOM->getMem(i)->setPosition(x,y);
}

void World::setDirectionMem(int i, int _direction) {
	LOM->getMem(i)->setDirection(_direction);
}

void World::setRow(int _row) {
	row = _row;
}

void World::setColumn(int _column) {
	column = _column;
}

void World::setCellSize() {
	cell = new char*[getColumn()];
	for (int i = 0; i < getColumn(); ++i) {
		cell[i] = new char[getRow()];
		for (int j = 0; j < getRow(); ++j) {
			setCellElmt(i,j,'.');
		}
	}
}

void World::setCellElmt(int i, int j, char karakter) {
	cell[i][j] = karakter;
}

void World::setLOM(int _nMax) {
	LOM = new ListOfMakhluk(_nMax);
}

void World::add(Makhluk* M) {
	LOM->add(M);
	setCellElmt(getXMem(LOM->getNEff()-1), getYMem(LOM->getNEff()-1), getIDMem(LOM->getNEff()-1));
}


//FUNGSI LAIN
bool World::isLOMEmpty() {
	return (LOM->getMem(0) == NULL);
}

void World::move(int i) {
	Point P = LOM->getMem(i)->getPosition();
	switch (getDirectionMem(i)) {
		/*
		-2	 1	2
		-3		3
		-4	-1	4
		*/
		case 1:
			P.move(0,-1);
			break;
		case 2:
			P.move(1,-1);
			break;
		case 3:
			P.move(1,0);
			break;
		case 4:
			P.move(1,1);
			break;
		case -1:
			P.move(0,1);
			break;
		case -2:
			P.move(-1,-1);
			break;
		case -3:
			P.move(-1,0);
			break;
		case -4:
			P.move(-1,1);
			break;
	}
	LOM->getMem(i)->setPosition(P);	
}

void World::undoMove(int i) {
	Point P = LOM->getMem(i)->getPosition();
	switch (getDirectionMem(i)) {
	/*
		-2	 1	2
		-3		3
		-4	-1	4
	*/
		case 1:
			P.move(0,getSpeedMem(i));
			break;
		case 2:
			P.move(-getSpeedMem(i),getSpeedMem(i));
			break;
		case 3:
			P.move(-getSpeedMem(i),0);
			break;
		case 4:
			P.move(-getSpeedMem(i),-getSpeedMem(i));
			break;
		case -1:
			P.move(0,-getSpeedMem(i));
			break;
		case -2:
			P.move(getSpeedMem(i),getSpeedMem(i));
			break;
		case -3:
			P.move(getSpeedMem(i),0);
			break;
		case -4:
			P.move(getSpeedMem(i),-getSpeedMem(i));
			break;
	}
	LOM->getMem(i)->setPosition(P);
}

void World::update() {
	LOM->update();

	//Memperbaiki posisi hewan yang berada di luar world
	for (int i = 0; i < LOM->getNEff(); ++i) {
		if ((getIDMem(i) != 'T') && ((getXMem(i) < 0) || (getXMem(i) > (getColumn()-1)) || (getYMem(i) < 0) || (getYMem(i) > (getRow()-1)))) {
			undoMove(i);
			for (int j = 1; j <= getSpeedMem(i); ++j) {
				/*
				-2	 1	2
				-3		3
				-4	-1	4
				*/
				// posisi ada di baris paling atas
				if (getYMem(i) == 0) {
					// posisi ada di kolom paling kiri
					if (getXMem(i) == 0) {
						if ((getDirectionMem(i) == -3) || (getDirectionMem(i) == 1)) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						} else if (getDirectionMem(i) == -2) {
							setDirectionMem(i, 4);
						}
					// posisi ada di kolom paling kanan
					} else if (getXMem(i) == (getColumn()-1)) {
						if ((getDirectionMem(i) == 3) || (getDirectionMem(i) == 1)) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						} else if (getDirectionMem(i) == 2) {
							setDirectionMem(i, -4);
						}
					} else {
						if (getDirectionMem(i) == 1) {
							setDirectionMem(i, -1);
						} else if (getDirectionMem(i) == 2) {
							setDirectionMem(i, 4);
						} else if (getDirectionMem(i) == -2) {
							setDirectionMem(i, -4);
						}
					}
				// posisi ada di baris paling bawah
				} else if (getYMem(i) == (getRow()-1)) {
					// posisi ada di kolom paling kiri
					if (getXMem(i) == 0) {
						if ((getDirectionMem(i) == -3) || (getDirectionMem(i) == -1)) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						} else if (getDirectionMem(i) == -4) {
							setDirectionMem(i, 2);
						}
					// posisi ada di kolom paling kanan
					} else if (getXMem(i) == (getColumn()-1)) {
						if ((getDirectionMem(i) == 3) || (getDirectionMem(i) == -1)) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						} else if (getDirectionMem(i) == 4) {
							setDirectionMem(i, -2);
						}
					} else {
						if (getDirectionMem(i) == -1) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						} else if (getDirectionMem(i) == 4) {
							setDirectionMem(i, 2);
						} else if (getDirectionMem(i) == -4) {
							setDirectionMem(i, -2);
						}
					}
				} else {
					// posisi ada di kolom paling kiri
					if (getXMem(i) == 0) {
						if ((getDirectionMem(i) == -2) || (getDirectionMem(i) == -3) || (getDirectionMem(i) == -4)) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						}
					// posisi ada di kolom paling kanan
					} else if (getXMem(i) == (getColumn()-1)) {
						if ((getDirectionMem(i) == 2) || (getDirectionMem(i) == 3) || (getDirectionMem(i) == 4)) {
							setDirectionMem(i, (-1*getDirectionMem(i)));
						}
					}
				}
				move(i);
			}	
		}
	}

	//Memeriksa makhluk yang posisinya sama
	for (int i = 0; i < LOM->getNEff(); ++i) {
		for (int j = i+1; j < LOM->getNEff(); ++j) {
			if (LOM->getMem(i)->getPosition() == LOM->getMem(j)->getPosition()) {
				if (getStrengthMem(i) >= getStrengthMem(j)) {
					LOM->remove(j);
				} else {
					LOM->remove(i);
				}	
			}
		}

	}

	//Mengompress size dari mem
	LOM->compress();
}

void World::print() {
	//Inisialisasi semua cell menjadi '.'
	for (int i = 0; i < getRow(); ++i) {
		for (int j = 0; j < getColumn(); ++j) {
			setCellElmt(j,i,'.');
		}
	}

	// Update ID di Cell
	for (int i = 0; i < LOM->getNEff(); ++i) {
		setCellElmt(getXMem(i),getYMem(i),getIDMem(i));
	}

	// Menampilkan
	cout << "\033[2J\033[1;1H";
	for (int i = 0; i < getRow(); i++) {
		for (int j = 0; j < getColumn(); j++) {
			cout << getCellElmt(j,i) << ' ';
		}
		cout << endl;
	}
	/*
	for (int i = 0; i < LOM->getNEff(); i++) {
		cout << "(" << getXMem(i) << "," << getYMem(i) << ")" << endl;
		cout << "Direction: " << getDirectionMem(i) << endl;
	}
	cout << endl;
	*/
}