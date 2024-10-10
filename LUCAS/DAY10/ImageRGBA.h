#pragma once
#include "ImageBase.h"
#include <iostream>
#include "interface_rgba.h"
using namespace std;
class ImageRGBA :
    public ImageBase , public interface_rgba
{
public:
    ImageRGBA(int _w, int _h, double _a);
    void showInfo() override;

    const double getTransparent() { return A; };

    // Inherited via interface_rgba
    virtual void funtion1() override;
    virtual void funtion2() override;
    virtual void funtion3() override;

private: 
    int depth = 3;
    double A;
};

