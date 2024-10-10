#pragma once
#include "ImageBase.h"
#include <iostream>
using namespace std;
class Image1 : public ImageBase
{
public:	
	Image1(int _w, int _h) : ImageBase(_w, _h) {};
	void showInfo() override;

	int getProtect() {
		return ImageBase::protect;
	}
};

