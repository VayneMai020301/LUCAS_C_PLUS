// DAY8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <set>

using namespace std; // STL (Standard Library)

void show(int a) {
    cout << "Gia tri cua a: " << a << endl;
}
void tinh_binh_phuong(int a) {
    cout << "Gia tri binh phuong cua a: " << a*a << endl;
}
void tinh_can(int a) {
    cout << "Gia tri can ban 2 cua a: " << sqrt(a) << endl;
}

class Image {
public:
    ~Image() {
        cout << "Call Destructor ..." << endl;
    }
    int w = 101;
};
int main()
{
    /*map static allocate*/
    Image img_static;
    std::map<std::string, Image> map_image;
    map_image[std::string("image")] = img_static;

    // init
    std::map<std::string, std::function<void(int)>> map_function;

    /* Add */
    map_function[std::string("func_1")] = show;
    map_function[std::string("tinh_binh_phuong")] = tinh_binh_phuong;
    map_function[std::string("tinh_binh_phuong")] = tinh_can; /* Set */

    /* Get */
    map_function[std::string("func_1")](19);
    map_function[std::string("tinh_binh_phuong")](100);

    /* Get For */
    for (const auto& pair : map_function) {
        cout << "Key: " << pair.first << endl;
        pair.second(10);
    }

    /* Lambda */
    Image* img = new Image();
    auto add_function = [&](double a) -> void {
        cout << "Gia tri cua a + a: " << a + a << endl;
    };
    map_function[std::string("tinh_tong")] = add_function;

    /*Get*/
    map_function[std::string("tinh_tong")](200);

    /* Find */
    auto iterator = map_function.find(std::string("tinh_tong"));
    if (iterator != map_function.end()) {
        cout << "Co key tinh_tong trong map" << std::endl;
    }
    /* Xoa*/
    if (iterator != map_function.end()) {
        map_function.erase(iterator);
    }
    /*Recheck */
    iterator = map_function.find(std::string("tinh_tong"));
    if (iterator == map_function.end()) {
        cout << "pair co key tinh_tong da bi xoa " << std::endl;
    }

    if (map_function.find(std::string("tinh_tong")) != map_function.end()) {
        map_function[std::string("tinh_tong")](200);
    }

    /*int a = 100;
    auto add_w = [=](int a)->void {
        (*img).w = 4000;
        a = 1000;
    };
    add_w(a);*/
    delete img;
    cout << "--------------------------SET (std::unique_ptr) -------------------------- " << endl;
    {
        Image* img = new Image();
        std::unique_ptr<Image> img_unique = std::make_unique<Image>();

        std::set<std::unique_ptr<Image>> set_image;
        /* Add */
        set_image.insert(std::move(img_unique));
        set_image.insert(std::move(img_unique));
        
        std::unique_ptr<Image> img_unique_1 = std::make_unique<Image>();
        img_unique_1->w = 102;
        /* Insert */
        set_image.insert(std::move(img_unique_1));

        /* Tim kiem */
        auto iter = set_image.find(img_unique);
        if (iter != set_image.end()) {
            cout << "phan tu img_unique co trong set " << endl;
        }

        /* Xoa */
        if (iter != set_image.end()) {
            set_image.erase(iter);
        }
        /* Recheck */
        iter = set_image.find(img_unique);
        if (iter == set_image.end()) {
            cout << "phan tu img_unique khong co trong set " << endl;
        }

        /* Duyet */
        for (const auto& iter : set_image) {
            cout << "Gia tri w cua iter la: " << iter->w << endl;;
        }
        /* */
        delete img;
    }
    cout << "--------------------------SET (static allocate) -------------------------- " << endl;
    std::set<Image*> set_static;
    {
        Image img;
        
        set_static.insert(&img);
        set_static.insert(&img);
        set_static.insert(&img);
    }
    for (const auto& iter : set_static){
        iter->w = 5000;
        cout << "Gia tri cua w la: " << iter->w << endl;
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
