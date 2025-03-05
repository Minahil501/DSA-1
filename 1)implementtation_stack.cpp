#include <iostream>
#include <string>
using namespace std;
class stack {
protected:
	int* arr;
	int currentsize;
	int maxsize;
public:
	stack() {} //default
	stack(int s) { //parametized
		currentsize = 0;
		maxsize = s;
		arr = new int[maxsize];
	}
	stack(stack& l) { //copy
		currentsize = l.currentsize;
		maxsize = l.maxsize;
		arr = new int[l.maxsize];
		for (int i = 0; i < currentsize; i++) {
			arr[i] = l.arr[i];
		}
	}
	~stack() {
		delete[]arr;
		arr = nullptr;
	}
	virtual void push(int value) = 0;
	virtual int pop() = 0;
	virtual void top() = 0;
	virtual bool full() = 0;
	virtual bool empty() = 0;
	virtual void search(int v) = 0;
	virtual void sort() = 0;
        virtual void reverse(mystack s, int& size)=0;
};
class mystack :public stack {
public:
	mystack() {}
	mystack(int s) :stack(s) {}
	void display() {
		cout << "currentsize is: " << currentsize << endl;
		for (int i = 0; i < currentsize; i++) {
			cout << "index " << i << ") " << arr[i] << " " << endl;
		}
	}
	void push(int v)override {
		if (full()) { cout << "stack is full"; }
		else {
			arr[currentsize++] = v;
		}
	}
	int pop()override {
		return arr[--currentsize];
	}
	bool full() {
		return currentsize == maxsize;
	}
	bool empty() {
		return currentsize == 0;
	}
	void top() {
		cout << arr[currentsize - 1];
	}
	void search(int v) {
		for (int i = 0; i < currentsize; i++) {
			if (arr[i] == v) { cout << " found at index " << i << endl; }
			else { cout << "value not present" << endl; }
		}
	}
	void sort() {
		for (int i = 0; i < currentsize; i++) {
			int small = i;
			for (int j = i + 1; j < currentsize; j++) {
				if (arr[j] > arr[small]) { small = j; }//descending
			}
			swap(arr[i], arr[small]);
			cout << arr[i] << " ";
		}
	}
	void reverse(mystack s, int& size) {
		mystack s1(size);
		mystack s2(size);
		while (!s.empty()) {
			s1.push(s.pop());
		}
		cout << "reversed stack is " << endl;
		s1.display();
	}

};
int main() {
	int size;
	cout << "Enter the size of the stack: ";
	cin >> size;
	mystack m(size);
	int choice, value;

	do {
		cout << "\nMenu:" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Display" << endl;
		cout << "4. Check if Full" << endl;
		cout << "5. Check if Empty" << endl;
		cout << "6. View Top Element" << endl;
		cout << "7. Search Element" << endl;
		cout << "8. Sort Stack" << endl;
		cout << "9. Reverse Stack" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to push: ";
			cin >> value;
			m.push(value);
			break;
		case 2:
			if (!m.empty()) {
				cout << "Popped: " << m.pop() << endl;
			}
			else {
				cout << "Stack is empty, nothing to pop." << endl;
			}
			break;
		case 3:
			m.display();
			break;
		case 4:
			if (m.full()) {
				cout << "Stack is full." << endl;
			}
			else {
				cout << "Stack is not full." << endl;
			}
			break;
		case 5:
			if (m.empty()) {
				cout << "Stack is empty." << endl;
			}
			else {
				cout << "Stack is not not empty." << endl;
			}
			break;
		case 6:
			if (!m.empty()) {
				cout << "Top element: ";
				m.top();
			}
			else {
				cout << "Stack is empty, no top element." << endl;
			}
			break;
		case 7:
			cout << "Enter value to search: ";
			cin >> value;
			m.search(value);
			break;
		case 8:
			m.sort();
			break;
		case 9:
			m.reverse(m, size);
			break;
		case 10:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice! Please enter a number between 1 and 10." << endl;
		}
	} while (choice != 10);

	return 0;
}
