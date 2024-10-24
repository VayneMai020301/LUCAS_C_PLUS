#pragma once
#include "ImageBase.h"
#include <iostream>
using namespace std;
class Image3 :
    public ImageBase
{
public:
    Image3(int _w, int _h) : ImageBase(_w, _h) {};

    void showInfo() override;
};

