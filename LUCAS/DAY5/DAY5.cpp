// DAY5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Red: std::cout    << "\033[31m" << "This text is red! " <<  i << "\033[0m" << std::endl;
Green: std::cout  << "\033[32m" << "This text is green! " << i << "\033[0m" << std::endl;
Yellow: std::cout << "\033[32m" << "This text is green! " << i << "\033[0m" << std::endl;
*/
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx_foreground;
//std::mutex mtx_foreground_green;
//std::mutex mtx_foreground_yellow;

using namespace std;

void show_red(int thread_id, int time) {
	for (int i = 0; i < time; i++) {
		mtx_foreground.lock();
		cout << "\033[31m" << "ID:" << thread_id << " Count << " << i << "\033[0m" << endl;
		mtx_foreground.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void show_green(int thread_id, int time) {
	for (int i = 0; i < time; i++) {
		mtx_foreground.lock();

		cout << "\033[32m" << "ID:" << thread_id << " Count << " << i << "\033[32m" << endl;
		mtx_foreground.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void show_yellow(int thread_id, int time) {
	for (int i = 0; i < time; i++) {
		mtx_foreground.lock();

		cout << "\033[33m" << "ID:" << thread_id << " Count << " << i << "\033[33m" << endl;
		mtx_foreground.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
class Image {
public:
	Image() {
		cout << "Calling Constructor ..." << endl;
	}
	~Image() {
		cout << "Calling Destructor ..." << endl;
	}
	int w = 10;
};

/* Truyen gia tri */
void increase_value(Image img) {
	img.w += 100;
}

/* Truyen pointer */
void increase_pointer(Image* img) {
	img->w += 100;
}

/* Truyen tham chieu */
void increase_ref(Image *img) {
	img->w += 100;
}

/* Truyen tham chieu */
void increase_ref_2(Image & img) {
	img.w += 100;
}
void increase_num(int * a) {
	cout << "Dia chi cua a la " << a << endl;
	(*a) = (*a) + 100;
}
int main()
{	
	/*std::thread t1(show_red,    1, 10);
	std::thread t2(show_green,  2, 10);
	std::thread t3(show_yellow, 3, 10);
	t1.join();
	t2.join();
	t3.join();*/

	Image* img = new Image();
	Image* img2 = &(*img);
	//Image ref = *(&(*img));
	int a = 10;
	int *p = &a;

	cout << "Dia chi cua o nho " << &a << endl;	
	std::thread t_change_w(increase_num, &a);

	cout << "Gia tri cua a la: " << a << endl;

	t_change_w.join();
	cout << "Hello World!\n";
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
