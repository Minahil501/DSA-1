#include <iostream>
#include <string>
using namespace std;
template <typename T>
class AbstractStack{
public:
	T* stack;
	int maxsize;
	int currentsize;
	AbstractStack(){}
	AbstractStack(T s){
		currentsize = 0;
		maxsize = s;
		stack = new T[maxsize];
	}
	virtual void push(T value) = 0; //adds value
	virtual T pop() = 0; //pops out value
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;

	~AbstractStack() { //destructor
		delete[]stack;
		stack = nullptr;
	}
};

template <typename T>
class mystack :public AbstractStack<T>{
public:
	mystack(){} //default
	mystack(int s) :AbstractStack<T>(s){} //parameter
	void push(T value)override{
		if (isFull()){ cout << "stack is full"; }
		else{
			stack[currentsize] = value;
			currentsize++;
		}
	}
	T pop()override{
		if (!isEmpty()){
			return stack[--currentsize];
		}
		else{
			cout << "your stack is empty" << endl;
		}
	}
	T top()const override {
		return stack[currentsize - 1];
	}
	bool isEmpty() const override {
		return currentsize == 0;
	}
	bool isFull() const override{
		return currentsize == maxsize;
	}
	void display(){
		for (int i = 0; i < currentsize; i++){
			cout << stack[i] << " " << endl;
		}
	}
	void menu(){
		cout << "Menu:" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Top" << endl;
		cout << "4. Check if empty" << endl;
		cout << "5. Check if full" << endl;
		cout << "6. Reverse stack" << endl;
		cout << "7. Display" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter your choice: ";

	}
	void reverse(T* s1, T*s2, int& s) { //reverse
		for (int i = 0; i < s; ++i) {
			s2[i] = s1[s - i - 1];
		}
	}
	void display_reversestack(T* s1, T* s2, int& s){
		reverse(s1, s2, s);
		for (int i = 0; i < s; ++i) {
			cout << s2[i] << " " << endl;
		}
	}
};

int main() {
	int size;
	cout << "Enter the size of the stack: ";
	cin >> size;
	mystack<int> int_stack(size);
	int* reversed_stack = new int[size];
	int choice, value, data_type;
	do {
		int_stack.menu();
		cin >> choice;
		switch (choice) {
		case 1:
			for (int i = 0; i < size; i++){
				cout << "Enter value to push: ";
				cin >> value;
				int_stack.push(value);
			}
			break;

		case 2:
				cout << int_stack.pop() << " popped from the stack." << endl;
			break;

		case 3:
			if (!int_stack.isEmpty()) {
				value = int_stack.top();
				cout << "Top element is: " << value << endl;
			}
			else {
				cout << "Stack is empty!" << endl;
			}
			break;

		case 4:
			if (int_stack.isEmpty()) {
				cout << "Stack is empty." << endl;
			}
			else {
				cout << "Stack is not empty." << endl;
			}
			break;

		case 5:
			if (int_stack.isFull()) {
				cout << "Stack is full." << endl;
			}
			else {
				cout << "Stack is not full." << endl;
			}
			break;

		case 6:
			int_stack.display_reversestack(int_stack.stack,reversed_stack,size);
				break;
		case 7:
			cout << "Displaying stack" << endl;
			int_stack.display();
			break;
		case 8:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 8);

	return 0;
}

