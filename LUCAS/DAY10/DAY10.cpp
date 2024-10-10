// DAY10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Image1.h"
#include "Image3.h"
#include "ImageRGBA.h"
using namespace std;
int main()
{
    {
        Image1 img(100, 200);
        img.showInfo();
        int protect = img.getProtect();
        cout << "Gia tri cua W la: " << img.getW() << endl;
        cout << "Gia tri cua H la: " << img.getH() << endl;

        img.setH(300);
        img.setW(400);

        cout << "Gia tri cua W la: " << img.getW() << endl;
        cout << "Gia tri cua H la: " << img.getH() << endl;

        float distance = img.distance_point_to_point(100, 200, 300, 400);
        Image3 img3(100, 200);
        img3.showInfo();

        ImageRGBA imgRGBA(100, 200, 0.1);
        cout << "Transparent is: " << imgRGBA.getTransparent() << endl;
        imgRGBA.showInfo();
        imgRGBA.funtion1();
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
