#pragma once
#include <iostream>	
#include "ImageBase.h"
using namespace std;
class Image1: public ImageBase
{
public:
	Image1(int _w);	// Declaration (Khai bao)
	~Image1();		// Declaration
	Image1(const Image1& other);

	void run() override;
	void forcerun() override;
};

