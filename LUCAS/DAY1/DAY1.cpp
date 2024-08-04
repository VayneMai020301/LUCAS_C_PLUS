// DAY1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int tinh_tong(int a, int b) {
    int s = a + b;
    return 0;
}

int* tinh_tong_2(int a, int b) {
    int sum = a + b;
    int* p = &sum;
    return p;
}

struct ImgSize
{
    int w; 
    int h;
    int depth;

    ~ImgSize() {
        std::cout << "Calling Destructor of class ImgSize\n";
    }
};
class Img {
    public:
        int w;
        int h;
        int depth;
        ImgSize*  imgSize =new ImgSize();
    private:
        
        
        int* p = &depth;
    public:
        
        // Overloading Constructor
        Img() {
            std::cout << "Calling Constructor 0 of class Img\n";
            w = 0;
            h = 0;
            depth = 1;
        };
        Img(int _w, int _h) {
            std::cout << "Calling Constructor 1 of class Img\n";
            imgSize->w = _w;
            imgSize->h = _h;
            imgSize->depth= 1;

            w = _w;
            h = _h;
            depth = 1;
        };
        Img(int _w, int _h, int _depth) {
            std::cout << "Calling Constructor 2 of class Img\n";
            w = _w;
            h = _h;
            depth = _depth;
            imgSize->w = _w;
            imgSize->h = _w;

            imgSize->depth = _depth;
        };

        // Destructor
        ~Img() {
            std::cout << "Calling Destructor of class Img\n";
            delete imgSize;
        }
};

int main()
{
    int a = 10;
    
    //std::cout << "Tong a va b " << tinh_tong(100, 200) << std::endl;
    if (tinh_tong(100, 200)) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    // Pointer
    int* p = &a;
    std::cout << "Gia tri cua p " << p << std::endl;
    std::cout << "Gia tri cua dia chi ma con tro p tro toi " << *p << std::endl;
    std::cout << "Gia tri cua a " << a << std::endl;

    (*p) = 100;
    std::cout << "Gia tri cua dia chi ma con tro p tro toi " << *p << std::endl;
    std::cout << "Gia tri cua a " << a << std::endl;

    // Con tro ham 
    int* s = tinh_tong_2(100, 500);
    std:cout << "Dia chi cua s la " << s << std::endl;

    // Delete s (Thu hoi lai vung nho ma con tro s dang tham chieu toi)
    //delete p;
    s = nullptr;
    // cout gia tri cua s
    std::cout << "Dia chi cua s la " << s << std::endl;
    // set s=nullptr

    // cout gia tri cua s 

    //
    int** q = (&p);
    (**q) = 200;
    std::cout << "Gia tri cua a " << a << std::endl;
    std::cout << "Gia tri cua dia chi ma con tro p tro toi " << *p << std::endl;
    std::cout << "Gia tri cua dia chi cua dia chi ma con tro q tham chieu toi " << **q << std::endl;

    // Tao object img tu class Img (Dynamic Allocate)
    Img* img = new Img(100, 400, 3);
    std::cout << "Chieu dai cua anh la: " << img->w << std::endl;
    std::cout << "Chieu rong cua anh la: " << img->h << std::endl;

    // Tao object img tu class Img (Static Allocate)
    {
        Img img2(100, 400, 3);
        //std::cout << "Chieu cao cua anh la: " << img2.h << std::endl;
        //std::cout << "Chieu rong cua anh la: " << img2.w << std::endl;
        std::cout << "Chieu cao cua anh la: " << img2.imgSize->w << std::endl;
        std::cout << "Hello World!\n";
    }
    delete img;
    /*
    * Con trỏ p không delete được vì nó không được khởi tạo bằng new (cấp phát động)
    */


    /*
    * Hàm con trỏ là hàm trả về một con trỏ
    * Con trỏ hàm là con trỏ, trỏ tới một hàm
    */
    std::cout << "Program paussing ...";
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
