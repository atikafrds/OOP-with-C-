#include "World.h"

int main() {
	World W1;
	World W2 = W1;
	World* W3 = &W2;
	W3->print();
	return 0;
}