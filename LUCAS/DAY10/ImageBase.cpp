#include "ImageBase.h"

void ImageBase::setW(int _w)
{
	w = _w;
}

void ImageBase::setH(int _h)
{
	h = _h;
}

const int ImageBase::getW()
{
	return w;
}

const int ImageBase::getH()
{
	return h;
}

float ImageBase::distance_point_to_point(double x1, double y1, double x2, double y2)
{
	return 1.0;
}

float ImageBase::distance_point_to_line(double x1, double y1, double A, double B, double C)
{
	return 2.0;
}

float ImageBase::distance_point_circle(double x1, double y1, double A, double B, double R)
{
	return 3.0f;
}