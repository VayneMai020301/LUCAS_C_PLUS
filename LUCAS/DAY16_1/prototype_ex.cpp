#include "prototype_ex.h"

void prototype_ex::run()
{
	HouseA* houseA = new HouseA("house A");
	cout << "Original Objetct: ";
	houseA->show();

	cout << "Cloned Objetct: ";
	client(houseA);
}

