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
string convert(string x, int size) {
	mystack m1(size);
	string result;
	for (int i = 0; i < size; i++) {
		if (x[i] >= '0' && x[i] <= '9' || x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z') {
			result += x[i];
		}
		if (x[i] == '+' || x[i] == '/' || x[i] == '*' || x[i] == '-') {
			m1.push(x[i]);
		}
		if (x[i] == '(' || x[i] == '{' || x[i] == '[') {
			m1.push(x[i]);
		}
		if (x[i] == ')' || x[i] == '}' || x[i] == ']') {
			result += m1.pop();
			m1.pop();
		}
	}
	while (!m1.empty()) {
		result += m1.pop();
	}
	return result;
}
string reverse(string x, int size) {
	string reversed(size, ' ');
	for (int i = 0; i < size; i++) {
		char ch = x[size - i - 1];
		if (ch == '(') reversed[i] = ')';
		else if (ch == ')') reversed[i] = '(';
		else if (ch == '{') reversed[i] = '}';
		else if (ch == '}') reversed[i] = '{';
		else if (ch == '[') reversed[i] = ']';
		else if (ch == ']') reversed[i] = '[';
		else reversed[i] = ch;
	}
	return reversed;
}
string reverse_again(string x, int size) {
	string ans1(size, ' ');
	for (int i = 0; i < size; i++) {
		ans1[i] = x[size - i - 1];
	}
	return ans1;
}
void postfixevaluation(string a, int size) {
		mystack s(size);
		int ans;
		int op1, op2;
		char waste;
		for (int i = 0; i <= size - 1; i++) {
			if (a[i] >= '0' && a[i] <= '9') {
				s.push(a[i] - 48);
			}
			else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				op2 = s.pop();
				op1 = s.pop();
				switch (a[i]) {
				case '+':
					ans = op1 + op2;
					break;
				case '-':
					ans = op1 - op2;
					break;
				case '*':
					ans = op1 * op2;
					break;
				case '/':
					ans = op1 / op2;
					break;
				}
				s.push(ans);
			}
			else {
				waste = a[i];
			}
		}
		cout << "result is: " << static_cast<int>(s.pop()) << endl;
	}
	void prefixevaluation(string a, int size) {
		mystack s(size);
		int ans;
		int op1, op2;
		char waste;
		for (int i = size - 1; i >= 0; i--) {
			if (a[i] >= '0' && a[i] <= '9') {
				s.push(a[i] - 48);
			}
			else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				op1 = s.pop();
				op2 = s.pop();
				switch (a[i]) {
				case '+':
					ans = op1 + op2;
					break;
				case '-':
					ans = op1 - op2;
					break;
				case '*':
					ans = op1 * op2;
					break;
				case '/':
					ans = op1 / op2;
					break;
				}
				s.push(ans);
			}
			else {
				waste = a[i];
			}
		}
		cout << "result is: " << static_cast<int>(s.pop()) << endl;
	}
	int main() {
		string infix, a, b, c;
		int choice;
		cout << "-------------ENTER SINGLE DIGIT EXPRESSION---------------" << endl;
		cout << "ENTER INFIX EXPRESSION: ";
		cin >> infix;
		int size = infix.length();
		do {
			cout << "1. CONVERT TO POSTFIX AND EVALUATE" << endl;
			cout << "2. CONVERT TO PREFIX AND EVALUATE" << endl;
			cout << "3. EXIT" << endl;
			cout << "ENTER CHOICE: ";
			cin >> choice;
			switch (choice) {
			case 1: {
						string postfix = convert(infix, size);
						cout << "POSTFIX EXPRESSION: " << postfix << endl;
						postfixevaluation(postfix, postfix.length());
						break;
			}
			case 2: {
						cout << "PREFIX EXPRESSION: ";
				a = reverse(infix, size);
				b = convert(a, size);
				c = reverse_again(b, b.length());
				cout << c << endl;
				prefixevaluation(c, c.length());
						break;
			}
			case 3:
				cout << "EXITING..." << endl;
				break;
			default:
				cout << "INVALID CHOICE" << endl;
			}
		} while (choice != 3);
		return 0;
	}

