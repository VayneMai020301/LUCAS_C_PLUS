// DAY3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;


class Image {
public:
    Image(int _w, int _h) {
        w = _w;
        h = _h;
        cout << "Calling Constructor ... " << endl;
    }

    const int getArea() const {
        return w * h;
    }

    int getWidth() const {
        int a = 100; /* Khởi tạo biến mới */
        //w = 10;  /* Giá trị đã khởi tạo rồi, không thể set lại được nữa*/
        return w;
    }

    bool setWidth(int _newWidth) {
        try
        {
            w = _newWidth; /* Do something*/
        }
        catch (const std::exception&)
        {
            return false;
        }
        return true;
    }


    Image(const Image& other) {
        cout << "Copy Construct ..." << endl;
    }
    ~Image() {
        cout << "Calling Destructor ... " << endl;
    }

private:
    int w;
    int h;
};
Image* createRegularImageObject(int _w, int _h) {
    return new  Image(_w, _h);
}
std::unique_ptr<Image> createUniqueImageObject(int _w, int _h)  {
    return std::make_unique<Image>(_w, _h);
}
std::shared_ptr<Image> createSharedImageObject(int _w, int _h) {
    return std::make_shared<Image>(_w, _h);
}

int main()
{
    //Image* p = new Image(10,20);
    //p->w;
    //Image* q(p); // Copy 
    //p->w = 100;
    { /* Unique Pointer */
        //std::unique_ptr<Image> img = std::make_unique<Image>(30,30);
        //cout << "Dia chi cua unique pointer " << img;
        //cout << "Width " << img->w << endl ;
        //std::unique_ptr<Image> img1 = std::move(img);
        //cout << "Dia chi cua unique pointer " << img1;
        //if (img == nullptr) {
        //    /*Do not something */
        //}
        //else
        //{
        //    /* Block Code*/
        //}
        //cout << "Width " << img1->w << endl;


        //img = std::move(img1);
        //cout << "Dia chi cua unique pointer " << img;

        //cout << "Width " << img->w << endl;

        //if (img1 == nullptr) {
        //    cout << "Null ptr";
        //    /* Do not something */
        //}
        //else
        //{
        //    cout << "Width " << img1->w << endl;
        //}
    }
    /* Shared Pointer */

    {
        std::shared_ptr<Image> img = std::make_shared<Image>(200, 20);
        const int area = img->getArea();
        cout << "Dien tich cua anh la: "  << img->getArea() << endl;
        cout << "Num of Pointer " << img.use_count() << endl;
        cout << "Dia chi cua shared pointer " << img << endl;

        {
            std::shared_ptr<Image> img1 = img;
            cout << "Dia chi cua shared pointer " << img1 << endl;
            cout << "Num of Pointer " << img1.use_count() << endl;
        }
        cout << "Num of Pointer " << img.use_count() << endl;
        {
            std::shared_ptr<Image> img2 = img;
            cout << "Dia chi cua shared pointer " << img2 << endl;
            cout << "Num of Pointer " << img2.use_count() << endl;
            if (img2->setWidth(1000)) {
                cout << "Set Sucessfull ...";
                /*
                */
            }else{
                cout << "Set Failed ...";
                /* 
                */
            }
        }
        cout << "Num of Pointer " << img.use_count() << endl;
    }

    /* Call Function */
    const Image* image = createRegularImageObject(2, 9);
    Image* img2 = new Image(20, 1);
    //*image = *img2;
    image = new Image(20, 1);
    delete image;
    std::unique_ptr<Image> img = createUniqueImageObject(100,20);
    std::unique_ptr<Image> img1 = std::move(img);
    img1->getArea();
    //delete p;
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
