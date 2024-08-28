// DAY7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    std::vector<>
    std::map<>
*/
#include <iostream>
#include <functional>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Image {
    public:
        Image() {
            cout << "Calling Constructor ..." << endl;
        };
        Image(const Image & other) {
            cout << "Copy Constructor ..." << endl;
            cout << "Dia chi cua other " << &other << endl;
        };
        ~Image() {
            cout << "Calling Destructor ..." << endl;
        };
        int w = 100;

        void show() {
            cout << "Calling show function " << endl;
        };
};
int main()
{
    std::vector<Image> static_image;
    Image img;
    cout << "Dia chi cua img " << &img << endl;
    static_image.push_back(img);
    cout << "---------------------------" << endl;
    static_image.push_back(img);
    cout << "---------------------------" << endl;
    static_image.push_back(img);

    cout << "So phan tu co trong vector " << static_image.size() << endl;

    /* Duyet qua tung phan tu co trong vector */
    for (const auto &iter : static_image) {
        cout << "Gia tri w la:  " << iter.w << endl;
        cout << "Dia chi cua iter " << &iter << endl;
    };
    cout << "----------------------------------" << static_image.size() << endl;
    img.w = 2000;
    for (const auto& iter : static_image) {
        cout << "Gia tri w la:  " << iter.w << endl;;
        cout << "Dia chi cua iter " << &iter << endl;
    };

    cout << "------------------------------------- Dynamic " << endl;
    std::vector<Image*> dynamic_image;
    Image* imgp = new Image();
    cout << "Dia chi cua imgp khi khoi tao la: "<<  imgp << endl;
    dynamic_image.push_back(imgp);
    dynamic_image.push_back(imgp);
    dynamic_image.push_back(imgp);
    cout << "So phan tu co trong dynamic_image " << dynamic_image.size() << endl;

    /* Duyet qua tung phan tu
        auto: ngam dinh,kieu du lieu thuc su se duoc xac dinh tai thuoi diem run time
    */
    for (auto const& iter : dynamic_image) {
        cout << "Dia chi cua imgp " << iter << endl;
        cout << "Dia chi cua vung nho chua bien imgp " << &iter << endl;
        cout << "Gia tri w la:  " << iter->w << endl;
    }
    cout << "-------------------------------------" << dynamic_image.size() << endl;
    imgp->w = 2000;
    for (auto const &iter : dynamic_image) {
        cout << "Dia chi cua imgp " << iter << endl;
        cout << "Dia chi cua vung nho chua bien imgp " << &iter << endl;
        cout << "Gia tri w la:  " << (iter->w) << endl;
    }

    for (auto const& iter : dynamic_image) {
        (iter->w) = 4000; // thay doi gia tri cua w thong qua dia chi cua moi iteration
        //(*(&iter))->w = 4000; // Thay doi gia tri cua w thong qua dia chi cua vung nho tren vector 
    }
    cout << "Gia tri w cua imgp la: " << imgp->w << endl;

    for (auto const& iter : dynamic_image) {
        //(iter->w) = 4000; // thay doi gia tri cua w thong qua dia chi cua moi iteration
        (*(&iter))->w = 8000; // Thay doi gia tri cua w thong qua dia chi cua vung nho tren vector 
    }
    /* delete */
    for (auto const & iter : dynamic_image) {

        cout << "Dia chi cua iter la: " << iter << endl;
        //delete iter; // Xoa di vung nho cua bien imgp
        //delete &iter; // Xoa vung nho cua vector chua phan tu la iter
        break;
    }
    //delete imgp;
    if (imgp == nullptr) {
        cout << "imgp is nullptr :" << endl;
    }
    imgp = nullptr;
    if (imgp == nullptr) {
        cout << "imgp is nullptr :" << endl;
    }
    imgp->w;
    imgp->show();


    /* find element and xoa */
    cout << "-------------------------------- Find and delete " << endl;
    std::vector<Image*> dynamic_image_1;
    Image* img1 = new Image();
    Image* img2 = new Image();
    Image* img3 = new Image();
    dynamic_image_1.push_back(img1);
    dynamic_image_1.push_back(img2);
    dynamic_image_1.push_back(img3);

    /* Find img2 */
    /*for (auto iter = dynamic_image_1.begin(); iter < dynamic_image_1.end(); iter++) {
        if (iter != dynamic_image_1.end()) {
            cout << "Find " << endl;
        }
    }*/
    Image* img4 = new Image();
    std::vector<Image*>::iterator iterfind;
    iterfind = std::find(dynamic_image_1.begin(), dynamic_image_1.end(), img4);

    if (iterfind != dynamic_image_1.end()) {
        cout << "Find out img1 in the vector" << endl;
    }
    else {
        cout << "Can't find out" << endl;
    }
    /* Xoa phan tu trong vector */
    if (iterfind != dynamic_image_1.end()) {
        dynamic_image_1.erase(iterfind);
    }

    /* Resize */
    Image* img5 = new Image();
    std::vector<Image*> vector_size (2, nullptr);

    cout << "-----------------------" << endl;
    for (auto const& iter : vector_size) {
        cout << "Dia chi cua o nho tren vector : " << &iter << endl;
    }
    cout << "-----------------------" << endl;
    vector_size.push_back(img5);
    for (auto const& iter : vector_size) {
        cout << "Dia chi cua o nho tren vector : " << &iter << endl;
    }
    cout << "-----------------------" << endl;
    vector_size.resize(4);
    for (auto const& iter : vector_size) {
        cout << "Dia chi cua o nho tren vector : " << &iter << endl;
    }
    cout << "-----------------------" << endl;
    Image* img6 = new Image();
    Image* img7 = new Image();
    Image* img8 = new Image();
    Image* img9 = new Image();

    vector_size.push_back(img6);
    vector_size.push_back(img7);
    vector_size.push_back(img8);
    vector_size.push_back(img9);
    for (auto const& iter : vector_size) {
        cout << "Dia chi cua o nho tren vector : " << &iter << endl;
    }

    cout << "-----------------------" << endl;
    vector_size.resize(4);
    for (auto const& iter : vector_size) {
        cout << "Dia chi cua o nho tren vector : " << &iter << endl;
    }
    vector_size.push_back(img6);
    cout << "-----------------------" << endl;
    for (auto const& iter : vector_size) {
        cout << "Dia chi cua o nho tren vector : " << &iter << endl;
    }

    if (imgp != nullptr) {
        cout << "Gia tri w cua imgp la: " << imgp->w << endl;
    }

    for (int t = 0; t < vector_size.size(); ++t) {
        
        if ((&vector_size[t])!= nullptr) {
            cout << "Gia tri w cua imgp la: " << (&vector_size[t]) << endl;
        }
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
