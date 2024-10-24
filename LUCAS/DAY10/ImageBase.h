#pragma once
#include "interface_distance.h"
#include <iostream>
using namespace std;
class ImageBase : public interface_distance
{
public:
	int protect = 100;


public:
	ImageBase(int _w, int _h) : w(_w), h(_h) {};
	
	void setW(int _w);
	void setH(int _w);

	const int getW();
	const int getH();

	// Inherited via interface_distance
	virtual float distance_point_to_point(double x1, double y1, double x2, double y2) override;
	virtual float distance_point_to_line(double x1, double y1, double A, double B, double C) override;
	virtual float distance_point_circle(double x1, double y1, double A, double B, double R) override;

private:
	int w; 
	int h; 
	int depth;
	int protec1 = 200;
public:
	virtual void showInfo() {};
};

