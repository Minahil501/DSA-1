#include <iostream>
#include <string>
using namespace std;
template <class t>
class circularqueue{
protected:
	t*arr;
	int maxsize;
	int csize;
public:
	circularqueue(){}
	circularqueue(int s){
		maxsize = s;
		csize = 0;
		arr = new t[maxsize];
	}
	virtual void enqueue(t value) = 0;
	virtual t dequeue() = 0;
	virtual bool full() = 0;
	virtual bool empty() = 0;
	~circularqueue(){
		delete[]arr;
		arr = nullptr;
	}
};
template <class t>
class mycqueue :public circularqueue<t>{
	int front;
	int rear;
public:
	mycqueue(){}
	mycqueue(int s) :circularqueue(s){
		front = 0;
		rear = 0;
	}
	void enqueue(t value){
		arr[rear%maxsize] = value;
		rear++;
		csize++;

	}
	t dequeue(){
		t temp = arr[front%maxsize];
		front++;
		csize--;
		return temp;

	}
	bool empty(){
		return csize == 0;
	}
	bool full(){
		return csize == maxsize;
	}
	t peek(){
		return arr[front%maxsize];
	}
	t last(){
		return arr[rear%maxsize - 1];
	}
	int currentsize(){
		return rear - front;
	}
	void display(){
		cout << "max size is " << maxsize << endl;
		cout << "current size is " << csize << endl;
		cout << "current size is " << currentsize() << endl;
		for (int i = front; i < rear; i++){
			cout << arr[i%maxsize] << " " << endl;
		}
	}
};
int main(){
	mycqueue<string>m1(6);
	int choice = 0;
	string value;
	while (true) {
		cout << "....... Menu ......." << endl;
		cout << "1. ADD  customer" << endl;
		cout << "2. Remove first customer" << endl;
		cout << "3. Display Queue and no of people in a queue" << endl;
		cout << "4. view 1st customer" << endl;
		cout << "5. view last customer" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter name of customer: " << endl;
			cin >> value;
			m1.enqueue(value);
			break;
		case 2:
			value = m1.dequeue();
			cout << "customer removed is: " << value << endl;
			break;
		case 3:
			cout << m1.currentsize();
			cout << "no of customers" << endl;
			m1.display();
			break;
		case 4:
			cout << "1st customer is :" << m1.peek() << endl;
			break;
		case 5:
			cout << "last customer is :" << m1.last() << endl;
			break;
		case 6:
			cout << "Exiting program." << endl;;
			return 0;
		default:
			cout << "Invalid choice. Please try again" << endl;;
		}
	}
	return 0;
}
