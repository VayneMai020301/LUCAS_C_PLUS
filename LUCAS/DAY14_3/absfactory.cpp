#include "absfactory.h"
#include <iostream>
using namespace std; 


void absfactory::run()
{
	/* Tao ra 2 abstract factory */

	cout << " ---------------------- Create Product of Winfactory ---------------------- " << endl;
	WinFactory winFactory;
	client(winFactory);


	cout << " ----------------------Create Product of Macfactory ----------------------" << endl;
	MacFactory macFactory;
	client(macFactory);


	cout << " ----------------------Create Product of Linuxcfactory ----------------------" << endl;
	LinuxFactory linuxFactory;
	client(linuxFactory);
}

/* 3. Abstract Product  (Lop co so)*/

