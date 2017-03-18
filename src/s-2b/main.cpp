#include "World.h"
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <stdio.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

#define NB_ENABLE 0
#define NB_DISABLE 1

//KAMUS GLOBAL
char ch;

//HEADER
int kbhit();
void nonblock(int state);
bool keyhit();
void SaveToFile();

//PROGRAM UTAMA
int main() {
	srand(time(NULL));
	int row;
	int column;
	int nTumbuhan;
	int nHerbivora;
	int nKarnivora;
	int nOmnivora;

	cout << "\033[2J\033[1;1H";
	cout << "Masukkan besar Kolom: ";
	cin >> column;

	cout << "Masukkan besar Baris: ";
	cin >> row;

	cout << "Masukkan jumlah Tumbuhan yang ingin dibuat: ";
	cin >> nTumbuhan;

	cout << "Masukkan jumlah Herbivora yang ingin dibuat: ";
	cin >> nHerbivora;

	cout << "Masukkan jumlah Karnivora yang ingin dibuat: ";
	cin >> nKarnivora;

	cout << "Masukkan jumlah Omnivora yang ingin dibuat: ";
	cin >> nOmnivora;

	World* W = new World(row, column, row*column);
	
	//Inisialisasi Makhluk
	for (int i = 0; i < nTumbuhan; ++i) {
		W->add(new Tumbuhan);
	}

	for (int i = 0; i < nHerbivora; ++i) {
		W->add(new Herbivora);
	}

	for (int i = 0; i < nKarnivora; ++i) {
		W->add(new Karnivora);
	}

	for (int i = 0; i < nOmnivora; ++i) {
		W->add(new Omnivora);
	}

	//Insialisasi Posisi
	for (int i = 0; i < W->getLOM()->getNEff(); ++i) {
		bool isSame;
		do {
			isSame = false;
			W->setPositionMem(i, rand() % W->getColumn(), rand() % W->getRow());
			int j = 0;
			do {
				if ((i != j) && (W->getPositionMem(i) == W->getPositionMem(j))) {
					isSame = true;
				}
				++j;
			} while ((j < W->getLOM()->getNEff()) && (!isSame));
		} while (isSame);
	}

	//Mulai simulasi kehidupan
	bool stop = false;
	bool isPaused = false;
	do {
		do {
			W->print();
			W->update();
		} while ((!isPaused) && (!W->isLOMEmpty()) && (!keyhit()));
		
		if ((ch == 'q') || (ch == 'Q')) {
			stop = true;
		} else if ((ch == 'c') || (ch == 'C')) {
			cout << "\033[2J\033[1;1H";
			// Menyimpan kondisi world ke file eksternal
			cout << "Masukkan filename untuk menyimpan kondisi world: ";
			string filename;
			cin >> filename;
			ofstream outfile;
			outfile.open(filename.c_str());
			if (outfile.is_open()) {
				for (int i = 0; i < W->getRow(); ++i) {
					for (int j = 0; j < W->getColumn(); ++j) {
						outfile << W->getCellElmt(j,i) << ' ';
					}
					outfile << endl;
				}
				outfile << endl;
			}
			outfile.close();
			ch = 0;
		} else if ((ch == 'p') || (ch == 'P')) {
			isPaused = !isPaused;
			if (isPaused) {
				nonblock(NB_ENABLE);
				int i = 0;
				while (!i) {
					usleep(1);
					i = kbhit();
					if (i != 0) {
						ch = fgetc(stdin);
						if ((ch == 'n') || (ch == 'N') || (ch == 'p') || (ch == 'P')) {
							i = 1;
						} else {
							i = 0;
						}
					}
				}
				nonblock(NB_DISABLE);
			} else {
				ch = 0;
			}
		} else if ((ch == 'n') || (ch == 'N')) {
			nonblock(NB_ENABLE);
			int i = 0;
			while (!i) {
				usleep(1);
				i = kbhit();
				if (i != 0) {
					ch = fgetc(stdin);
					if ((ch == 'n') || (ch == 'N') || (ch == 'p') || (ch == 'P')) {
						i = 1;
					} else {
						i = 0;
					}
				}
			}
			nonblock(NB_DISABLE);
		} else if ((ch == 'i') || (ch == 'I')) {
			int i = 1 + (rand() % 4);
			if (i == 1) {
				W->add(new Tumbuhan);
			} else if (i == 2) {
				W->add(new Herbivora);
			} else if (i == 3) {
				W->add(new Karnivora);
			} else {
				W->add(new Omnivora);
			}

			i = W->getLOM()->getNEff()-1;
			bool isSame;
			do {
				isSame = false;
				W->setPositionMem(i, rand() % W->getColumn(), rand() % W->getRow());
				int j = 0;
				do {
					if ((i != j) && (W->getPositionMem(i) == W->getPositionMem(j))) {
						isSame = true;
					}
					++j;
				} while ((j < W->getLOM()->getNEff()) && (!isSame));
			} while (isSame);
			ch = 0;
		} else {
			ch = 0;
		}

		if (W->isLOMEmpty()) {
			stop = true;
		}
	} while (!stop);

	cout << "\033[2J\033[1;1H";
	delete W;
	return 0;
}

//IMPLEMENTASI HEADER
int kbhit() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state) {
    struct termios ttystate;
 
    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
 
    if (state==NB_ENABLE)
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    }
    else if (state==NB_DISABLE)
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
 
}

bool keyhit() {
	high_resolution_clock::time_point tBegin = high_resolution_clock::now();
	high_resolution_clock::time_point tEnd = high_resolution_clock::now();
	double time_span = 0;
	nonblock(NB_ENABLE);
	int i = 0;
	while ((!i) && ((time_span = duration_cast<chrono::microseconds>(tEnd - tBegin).count()) < 1000000)) {
		usleep(1);
		i = kbhit();
		if (i != 0) {
			ch = fgetc(stdin);
			if ((ch == 'q') || (ch == 'Q') || (ch == 'c') || (ch == 'C') || (ch == 'p') || (ch == 'P') || (ch == 'I') || (ch == 'i')) {
				i = 1;
			} else {
				i = 0;
			}
		}
		tEnd = high_resolution_clock::now();
	}
	nonblock(NB_DISABLE);

	if (time_span < 1000000) {
		return true;
	} else {
		return false;
	}
}