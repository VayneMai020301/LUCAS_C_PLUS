// DAY6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>

using namespace std;
int number = 0;
std::mutex number_mtx;
std::condition_variable cv;
std::mutex lock_number;
int count_number = 0;
bool ready;

void increase() {
    number_mtx.lock();
    for (int i = 0; i < 100000; i++) {
        number++;
    }
    number_mtx.unlock();
}

class Image {
public:
    Image() {
        cout << "Calling Constructor " << endl;
    };
    Image(const Image& other) {
        cout << "Copy Constructor " << endl;
    };
    ~Image() {
        cout << "Calling Destructor " << endl;
    }

    int w = 100;
};
void increaseW(Image img) {
    cout << "Dia chi cua img khi truyen gia tri: " << &img << endl;
    img.w += 100;
    cout << "Gia tri cua w la: " << img.w << endl;
}

void increaseWRef(Image *img) {
    cout << "Dia chi cua img khi truyen tham chieu: " << img << endl;
    img->w += 100;
}

void getW(Image* img) {
    if (img != nullptr) {
        img->w;
    }
}

void showKetQua(std::function<int(int, int)> func, int a, int b) {
    cout << "ket qua cua ham la : " << func(a, b) << endl;
}

// ham tra va thread
std::thread createThread(std::function<void(Image*)> func, Image *img) {
    std::thread t(func, img);
    return t;
}
// truyen vao thread
void runThread(std::thread *t) {
    t->join();
}

int tinh_chia(int a, int b) {
    return a / b;
};

// 

void increase_number(Image *img) { // Thread 1
    for (int i = 0; i <= 10; i ++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        {
            lock_number.lock();
            img->w++;
            cout << "Increase count_number: " << img->w << " --- ";
            lock_number.unlock();
            ready = true;
        }
        cv.notify_one();
    }
}

void receive_changes_1(Image *img) {
    while (true)
    {
        std::unique_lock<std::mutex> lock(lock_number);
        cv.wait(lock, [] {return ready; });
        cout << "Receive count_number: " << img->w << endl;
        if (img->w >= 111) {
            break;
        }
        ready = false;
    }
}
void receive_changes_2(Image *img) {
    while (true)
    {
        std::unique_lock<std::mutex> lock(lock_number);
        cv.wait(lock, [] {return ready; });
        
        cout << "--- Gia tri binh phuong" << img->w << endl;
        ready = false;
    }
}

int main()
{
    /*std::thread t1(increase);
    std::thread t2(increase);

    t1.join();
    t2.join();*/
    {
        // stack A used 
        // Lam den dau giai phong vung nho den do
        // free stack A
    }
    {
        // stack B used 
        // Lam den dau giai phong vung nho den do
        // free stack B
    }
    //Image img;
    //cout << "Dia chi img trong main_thread" << &img << endl;
    //{
        //std::thread t3 = createThread(increaseWRef, &img);
        //t3.join();
        //t3.join();
    //}
    //getW(&img);
    // << "Dia chi img trong main_thread" << &img << endl;
    //std::thread t3(increaseW, img);
    //t3.join();
    // 
    //showKetQua(tinh_chia, 100, 20);
    // 
    //runThread(&t3);

    //Image* img_ptr = new Image();
    // << "Dia chi img trong main_thread" << img_ptr << endl;
    //cout << "Gia tri cua number: " << number << endl;
    Image img;
    std::thread increase_thread (increase_number,   &img);
    std::thread receive_thread_1(receive_changes_1, &img);
    //std::thread receive_thread_2(receive_changes_2, &img);

    increase_thread.join();
    receive_thread_1.detach();
    //receive_thread_2.join();

    //std::this_thread::sleep_for(std::chrono::seconds(10));

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
