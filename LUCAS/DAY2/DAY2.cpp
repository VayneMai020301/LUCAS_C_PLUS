// DAY2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Size {
    int w; 
    int h;
};

class Img {

public:
    Size* size = new Size();
    Img(int _w, int _h) {

        size->w = _w;
        size->h = _h;
    }

    /* Override Shallow Copy */
    Img(const Img& img) {
        size = img.size;
        std::cout << "Calling Shallow Copy\n";
    }

    /* Override Deep Copy */
    /*Img(const Img& img){
        size = new Size();
        *size = *img.size;
        std::cout << "Calling Deep Copy";
    }*/

    ~Img() {
        std::cout << "Calling Destructor ...\n";
    }

public:
    int w; 
    int h;
};

int getW() {
    Img img(1, 2);
    std::cout << "Width: " << img.size->w << std::endl;
    return img.size->w;
}

Img* imgGlobal;
int getH() {
    imgGlobal  =new Img(1, 2);
    std::cout << "Width: " << imgGlobal->size->w << std::endl;
    return imgGlobal->size->h;
}

class BaseImg {
public:
    BaseImg(int _w, int _h, int _depth): w(_w), h(_h), depth(_depth){
        std::cout << "Calling BaseImg ...\n";
    };

    virtual void cal_threshold() { // Virual Method
       // std::cout << "cal_threshold in BaseImg";
    }; // Lop dan xuat co the dinh nghia lai hoac la khong

    virtual int getSizeImage ()= 0; // Pure Virtual Method
    virtual void detect_edge() {};
    virtual void detect_line() {};
    virtual void distance_point_to_point() {};

    protected :
        int w; 
        int h;
        int depth;
        int size_image;
};

class Img3 : public BaseImg {
public:
    Img3(int _w, int _h, int _depth) : BaseImg(_w, _h, _depth) {
        std::cout << "Calling Img3 Constructor ...\n";
    };
    int getSizeImage() override {
        return size_image;
    }

    /*re defination */
    void cal_threshold() override { 
        // std::cout << "Call threshold in Derivative";
    };

private: 
    int bit_per_pixel = 24;
};

class Img1 : public BaseImg {

public:
    Img1(int _w, int _h, int _depth) : BaseImg(_w, _h, _depth) {
        std::cout << "Calling Img1 Constructor ...\n";
        /* Modify */
        size_image = _w * _h * bit_per_pixel;
    };

    int getSizeImage() override {
        return size_image;
    }
private:
    int bit_per_pixel = 8;
};
int main()
{
    int x = getW();
    int y = getH();
    delete imgGlobal;

    int a = 10;
    int *b = &a;
    *b = 100;
    std::cout << "Dia chi cua bien a " << &a << std::endl;
    std::cout << "Dia chi cua bien b " << &b << std::endl;
    std::cout << "Gia tri cua bien a " << a << std::endl;

    /**/
    a = 300;
    std::cout << "Gia tri cua bien b " << *b << std::endl;
    std::cout << "Hello World!\n";

    /* Deep Copy */
    Img img1(100, 300);
    Img img2(img1);

    img1.size->w = 200;
    img1.size->h = 400;

    std::cout << "img2 w: " << img2.size->w << std::endl;
    std::cout << "img2 h: " << img2.size->h << std::endl;

    img2.size->w = 500;
    img2.size->h = 600;

    std::cout << "img1 w: " << img1.size->w << std::endl;
    std::cout << "img1 h: " << img1.size->h << std::endl;

    /*Deep Copy*/
    Img img3(100, 300);
    Img img4 = img3;

    img3.size->w = 200;
    img3.size->h = 400;

    std::cout << "img2 w: " << img4.size->w << std::endl;
    std::cout << "img2 h: " << img4.size->h << std::endl;

    img4.size->h = 500;
    img4.size->h = 600;

    std::cout << "img1 w: " << img3.size->w << std::endl;
    std::cout << "img1 h: " << img3.size->h << std::endl;

    /* Class va OOP */

    Img1* img5 = new Img1(200, 200, 1);
    img5->cal_threshold();
    Img3* img6 = new Img3(200, 200, 1);
    img6->cal_threshold();

    /* Casting static_cast<>() , dynamic_cast<>() */

    auto casting    = static_cast<Img1*> (img5);
    auto casting1   = static_cast<Img3*> (img6); // Compile

    auto casting2 = dynamic_cast<Img1*> (img5);
    casting2->cal_threshold();
    auto casting3 = dynamic_cast<Img3*> (img5);

    if (casting3 == nullptr) {
        std::cout << "nullptr" << std:: endl;
    }

    auto casting4 = dynamic_cast<BaseImg*> (img5);
    casting4->cal_threshold();

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
