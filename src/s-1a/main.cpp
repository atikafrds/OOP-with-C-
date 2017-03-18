#include "World.h"
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <stdio.h>
#include <chrono>

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
	do {
		W->print();
		W->update();
	} while ((!W->isLOMEmpty()) && (!keyhit()));
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
			if ((ch == 'q') || (ch == 'Q')) {
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