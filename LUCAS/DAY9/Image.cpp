#include "Image.h"

Image1::Image1(const Image1& other) 
{
	cout << "Calling Copy Constructor ..." << endl;
}
void Image1::run () // Virtual function (Ham ao)
{
	w = 100;
}
void Image1::forcerun() // Pure virtual Function (Ham thuan ao)
{

}
Image1::Image1(int _w) // Khoi tao 
{
	cout << "Calling Constructor ..." << endl;
	w = _w;
}
Image1::~Image1()
{
	cout << "Calling Destructor ..." << endl;
}
