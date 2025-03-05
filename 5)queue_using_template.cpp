#include <iostream>
#include <string>
using namespace std;
template <class t>
class queue{
protected:
	t*arr;
	int max;
	int c;
public:
	queue(){}
	queue(int m){
		max = m;
		arr = new t[max];
		c = 0;
	}
	queue(queue&l){
		max = l.max;
		arr = new t[l.max];
		for (int i = 0; i < max; i++){
			arr[i] = l.arr[i];
		}
	}
	~queue(){
		delete[]arr;
		arr = nullptr;
	}
	virtual void enq(t v) = 0;
	virtual t deq() = 0;
	virtual bool empty() = 0;
	virtual bool full() = 0;
	virtual void display() = 0;
	virtual t peek() = 0;

};
template <class t>
class myqueue :public queue<t>{
public:
	myqueue(){}
	myqueue(int s) :queue<t>(s){}
	void enq(t v){
		if (full()){ cout << "full"; }
		else{
			arr[c++] = v;
		}
	}
	t deq(){
		if (empty()){ cout << "empty"; }
		else{
			t temp = arr[0];
			c--;
			for (int i = 0; i < c; i++){
				arr[i] = arr[i + 1];
			}
			return temp;
		}
	}
	bool empty(){
		return c == 0;

	}
	bool full(){
		return max == c;
	}
	t peek(){
		return arr[0];
	}
	void display(){
		for (int i = 0; i< c; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int binary_search(int key, int s) {
		int low = 0;
		int high = s - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] == key) {
				return mid;
			}
			else if (arr[mid] < key) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		cout << "Key not found" << endl;
		return 0;
	}
	void sorted(){
		for (int i = 0; i < c; i++){
			int small = i;
			for (int j = i + 1; j < c; j++){
				if (arr[j] < arr[small]) { small = j; } 
			}
			t temp = arr[i];
			arr[i] = arr[small];
			arr[small] = temp;
		}
	}
};
template <class t>
void odd(myqueue<t>&m1, int size){
	myqueue <t>m2(size);
	while (!m1.empty()){
		int v = m1.deq();
		if (v % 2 != 0){
			m2.enq(v);
		}
	}
	m2.display();
	int max = 0;
	int current = 0;
	int secmax = 0;
	while (!m2.empty()){
		current = m2.deq();
		if (current > max){
			secmax = max;
			max = current;
			if (current > secmax && current < max){
				secmax = current;
			}
		}
	}
	cout << "max odd number is: " << max << endl;
	cout << "second max odd number is:" << secmax << endl;
}
int main() {
	int choice, value, size;
	cout << "ENTER QUEUE SIZE: ";
	cin >> size;
	myqueue<int> m1(size);

	do {
		cout << "1. ENQUEUE" << endl;
		cout << "2. DEQUEUE" << endl;
		cout << "3. DISPLAY" << endl;
		cout << "4. PEEK" << endl;
		cout << "5. SORT" << endl;
		cout << "6. SEARCH" << endl;
		cout << "7. ODD NUMBERS" << endl;
		cout << "8. EXIT" << endl;
		cout << "ENTER CHOICE: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "ENTER VALUE: " << endl;
			cin >> value;
			m1.enq(value);
			break;
		case 2:
			cout << "DEQUEUED: " << m1.deq() << endl;
			break;
		case 3:
			m1.display();
			cout << endl;
			break;
		case 4:
			cout << m1.peek();
			cout << endl;
			break;
		case 5:
			m1.sorted();
			cout << "SORTED QUEUE: " << endl;
			m1.display();
			cout << endl;
			break;
		case 6:
			cout << "ENTER VALUE TO SEARCH: " << endl;
			cin >> value;
			cout << "INDEX: " << m1.binary_search(value, size) << endl;
			break;
		case 7:
			odd(m1, size);
			cout << endl;
			break;
		case 8:
			cout << "EXITING..." << endl;
			break;
		default:
			cout << "INVALID CHOICE" << endl;
		}
	} while (choice != 8);

	return 0;
}

