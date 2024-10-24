#include "data_array.h"
void data_array::run()
{
	cout << "--------------- Cap phat tinh cho mang " << endl;
	{
		Image1 imgArr[3] = {
			Image1(100),Image1(200),Image1(300)
		};

		// Sua 
		imgArr[1] = Image1(400);

		// thay doi size ( khong duoc vi imgArr dang la mang tinh)
		/*imgArr[4] = {
			Image1(100),Image1(200),Image1(300),Image1(400)
		};*/

		// duyet qua tung phan tu 
		int number = sizeof(imgArr) / sizeof(imgArr[0]);
		cout << "So luong phan tu trong array la: " << number << endl;

		for (size_t i = 0; i < number; i++) {
			cout << "dia chi cua tung phan tu: " << &imgArr[i] << endl;
			cout << "gia tri cua w: " << imgArr[i].w << endl;
		}
	}

	cout << "--------------- cap phat mang dong -----------------" << endl;
	{
		Image1* imgArr = new Image1[3]{ 100,200, 300};
		cout << "dia chi cua vi tri 0: " << &imgArr[0] << endl;
		cout << "dia chi cua vi tri 1: " << &imgArr[1]<< endl;
		cout << "dia chi cua vi tri 2: " << &imgArr[2]<< endl;

		imgArr = new Image1[5]{ 100,200, 300, 400, 500}; // Resize (=> memory leak ; to prevent can use std::vector<>)
		cout << "dia chi cua vi tri 0: " << &imgArr[0]<< endl;
		cout << "dia chi cua vi tri 1: " << &imgArr[1]<< endl;
		cout << "dia chi cua vi tri 2: " << &imgArr[2]<< endl;
		cout << "dia chi cua vi tri 3: " << &imgArr[3]<< endl;
		cout << "dia chi cua vi tri 4: " << &imgArr[4]<< endl;

		// Duyet qua tung phan tu 
		for (size_t i = 0; i < 5; i++) {
			cout << "Dia chi cua vi tri " << i << &imgArr[i] << endl;
			cout << "Dia chi cua w o vi tri " << i << imgArr[i].w << endl;
		}
		
		delete[] imgArr;
	}

	cout << "--------------- cap phat dong cho tung phan tu trong mang tinh " << endl;
	{
		Image1* imgArr[] = {
			new Image1(100),
			new Image1(200),
			new Image1(300),
		};
		// For 
		for (size_t i = 0; i < 3; i++) {
			cout << "Dia chi cua tung thanh phan la: "<< imgArr[i] << endl;
			cout << "Gia tri cua w la: " << imgArr[i]->w << endl;
			delete imgArr[i];
		}
	}

	cout << " -------------------- END ARRAY-------------------- " << endl;
}
