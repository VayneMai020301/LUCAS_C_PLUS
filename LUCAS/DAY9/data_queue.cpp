#include "data_queue.h"

data_queue::data_queue()
{
}

data_queue::~data_queue()
{
}

data_queue::data_queue(const data_queue& other)
{
}

void data_queue::run()
{
	cout << " ---------------------------- QUEUE ---------------------------- " << endl;
	{
		// cap phat tinh
		std::queue<Image1*> queue;
		queue.push(new Image1(100));
		queue.push(new Image1(200));
		queue.push(new Image1(300));
		// xem phan tu phu dau tien 
		Image1* temp = queue.front();

		// 
		while (!queue.empty())
		{
			Image1* temp = queue.front();
			cout << "Gia tri w la: " << temp->w << endl;
			delete temp;
			queue.pop();
		}

		if (queue.empty()) {
			cout << "Queue rong ..." << endl;
		}
	}

	{
		// cap phat dong
		std::queue<Image1*> *queue =new std::queue<Image1*>;
		queue->push(new Image1(100));
		queue->push(new Image1(200));
		queue->push(new Image1(300));
		// xem phan tu phu dau tien 
		Image1* temp = queue->front();
		// 
		while (!queue->empty())
		{
			Image1* temp = queue->front();
			cout << "Gia tri w la: " << temp->w << endl;
			delete temp;
			queue->pop();
		}

		if (queue->empty()) {
			cout << "Queue rong ..." << endl;
		}
	}
}
