// DAY4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

template<typename T>
void swap(T a, T b) {
    std::cout << "Dia chi cua a " << &a << std::endl;
    std::cout << "Dia chi cua b " << &b << std::endl;

    T temp = a;
    a = b;
    b = temp;
};
class Ld {
    
public:
    std::function<std::unique_ptr<Image1>(int, int)> function_create_object;
    void setLambda() {
        function_create_object = [](int w, int h) -> std::unique_ptr<Image1> {
            return std::make_unique<Image1>(w, h);
        };
    };
};
class Image {
public:
    Image(int _w, int _h) : w(_w), h(_h) {
        std::cout << "Calling constructor Image ..." <<std::endl;
    };
    ~Image() {
        std::cout << "Calling Destructor Image ..." << std::endl;

    };


private:
    int w; int h;
    const int depth = 0;
};
class Image1 
{
public:
    Image1(int _w, int _h) : w(_w), h(_h){
        std::cout << "Calling constructor Image 1 ..." << std::endl;
    };
    ~Image1() {
        std::cout << "Calling Destructor Image 1 ..." << std::endl;

    };
private:
    const int depth = 1;
    int w;
    int h;
};

class Image3 
{
public:
    Image3(int _w, int _h) : w(_w), h(_h) {
        std::cout << "Calling constructor Image 3 ..." << std::endl;
    };
    ~Image3() {
        std::cout << "Calling Destructor Image 3 ..." << std::endl;

    };
private :
    const int depth = 3;
    int w;
    int h;
};
//std::unique_ptr<Image> createObjec(int _w, int h) {
//    return std::make_unique<Image>(_w, h);
//}
//template<class T>
//std::unique_ptr<T> createObjec(int _w, int h ) {
//    return std::make_unique<T>(_w, h);
//}

template <class T>
std::unique_ptr<T> create_unique_object(int _w, int _h) {
    return std::make_unique<T>(_w, _h);
}

template <class T>
std::shared_ptr<T> create_shared_object(int _w, int _h) {
    return std::make_shared<T>(_w, _h);
}
template<class T>
void getDepth(T* img) {
    Image* image_cast = (Image*)img; /* Explicit Convertion */
    cout << "Gia tri cua w la: " << image_cast->w << std::endl;
};

int main()
{

    int a = 10;
    std::cout << "Dia chi cua a " << &a <<std::endl;
    int b = 11;
    std::cout << "Dia chi cua b " << &b << std::endl;

    swap(a, b);
    std::cout << "Gia tri cua a la: " << a << std::endl;
    std::cout << "Gia tri cua b la: " << b <<std::endl;

    double c = 0.3;
    double d = 0.8;
    swap(c, d);
    std::cout << "Gia tri cua c la: " << &c << std::endl;
    std::cout << "Gia tri cua d la: " << &d << std::endl;
    //
    {
        std::unique_ptr<Image>  img  = create_unique_object<Image>(100, 200);
        
        std::unique_ptr<Image1> img1 = create_unique_object<Image1>(100, 200);
        std::unique_ptr<Image3> img3 = create_unique_object<Image3>(100, 200);
    }
    {
        {
            std::shared_ptr<Image>  img4 = create_shared_object<Image>(100, 200);
            std::shared_ptr<Image1> img5 = create_shared_object<Image1>(100, 200);
        }
        std::shared_ptr<Image3> img6 = create_shared_object<Image3>(100, 200);
    }

    Image* img      = new Image(100, 20);




    Image1* img1    = new Image1(100, 20);
    Image3* img3    = new Image3(100, 20);

    getDepth(img);
    getDepth(img1);
    getDepth(img3);
    /* Lamda */ 
    {
        std::function<std::unique_ptr<Image3>(int, int)> create_unique_object_function;
        auto create_unique_object_lambda = [](int _w, int _h) -> std::unique_ptr<Image3> {
            return std::make_unique<Image3>(_w, _h);
        };
        std::unique_ptr<Image3> img3 = create_unique_object_lambda(200, 3);
        create_unique_object_function = create_unique_object_lambda;
        std::unique_ptr<Image3> img4 = create_unique_object_function(2300, 2);
    }

    {
        Ld* ld = new     Ld();
        ld->setLambda();
        std::unique_ptr<Image1> img = ld->function_create_object(100,2);
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
