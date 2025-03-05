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
	virtual int top() = 0;
	virtual bool full() = 0;
	virtual bool empty() = 0;

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
	int top() {
		return arr[currentsize - 1];
	}

};
bool bracket_check(string x, int size) {
	mystack s1(size);
	for (int i = 0; i < size; i++) {
		if (x[i] == '{' || x[i] == '[' || x[i] == '(') {
			s1.push(x[i]);
		}
		else if (x[i] == '}' || x[i] == ']' || x[i] == ')') {
			if (s1.empty()) {
				return false;
			}
			else if (x[i] == '}' && s1.top() == '{' || x[i] == ']' && s1.top() == '[' || x[i] == ')' && s1.top() == '(') {
				s1.pop();
			}
			else { return false; }
		}
	}
	return s1.empty();
}
int main() {
	string expression;
	cout << "Enter an expression to check for balanced brackets: " << endl;
	cin >> expression;
	long size = expression.length(); 
	if (bracket_check(expression, size)) {
		cout << "The expression has balanced brackets." << endl;
	}
	else {
		cout << "The expression does not have balanced brackets." << endl;
	}
	return 0;
}
