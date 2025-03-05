#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};
class ll{
public:
	node* head;
	node*tail;
	ll(){
		head = nullptr;
		tail = nullptr;
	}
};
class dll :public ll{
public:
	dll() :ll(){}
	void insertathead(int v){
		node *nn = new node;
		nn->data = v;
		nn->next = nullptr;
		nn->prev = nullptr;
		if (head == nullptr && tail == nullptr){ //list empty
			head = nn;
			tail = nn;

		}
		else{
			nn->next = head;
			head->prev = nn;
			head = nn;
		}
	}
	void insertattail(int v){
		node *nn = new node;
		nn->data = v;
		nn->next = nullptr;
		nn->prev = nullptr;
		if (head == nullptr && tail == nullptr){ //list empty
			head = nn;
			tail = nn;

		}
		else{
			tail->next = nn;
			nn->prev = tail;
			tail = nn;
		}
	}
	void displayhead(){
		if (tail == nullptr && head == nullptr){
			cout << "empty" << endl;
		}
		else {
			node*t = head;
			while (1){
				cout << t->data << " ";
				t = t->next;
				if (t == nullptr){
					break;
				}
			}
		}
	}
	void displaytail(){
		if (tail == nullptr && head == nullptr){
			cout << "empty" << endl;
		}
		else {
			node*t = tail;
			while (1){
				cout << t->data << " ";
				t = t->prev;
				if (t == nullptr){
					break;
				}
			}
		}
	}
	int delathead(){
		if (head == nullptr && tail == nullptr){
			return 0;
		}
		if (head == tail){
			int rv = head->data;
			delete head;
			head = nullptr;
			tail = nullptr;
			return rv;
		}
		else {
			int rv = head->data;
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			return rv;
		}
	}
	int delattail(){
		if (head == nullptr && tail == nullptr){
			return 0;
		}
		if (head == tail){
			int rv = tail->data;
			delete tail;
			head = nullptr;
			tail = nullptr;
			return rv;
		}
		else {
			int rv = tail->data;
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
			return rv;
		}
	}
	void insertsorted(int v){
		if (head == nullptr&&tail == nullptr){
			node* nn = new node;
			nn->data = v;
			nn->next = nullptr;
			nn->prev = nullptr;
			head = nn;
			tail = nn;
		}
		else if (v <= head->data){
			insertathead(v);
		}
		else if (v >= tail->data){
			insertattail(v);
		}
		else {
			node* nn = new node;
			nn->data = v;
			nn->next = nullptr;
			nn->prev = nullptr;
			node*t = head;
			while (1){
				if (t->data<v && t->next->data>v){
					break;
				}
				else{
					t = t->next;
				}
			}
			nn->next = t->next;
			t->next->prev = nn;
			t->next = nn;
			nn->prev = t;
		}
	}
	int countd(){
		int count = 0;
		if (tail == nullptr && head == nullptr){
			cout << "empty" << endl;
		}
		else {
			node*t = head;
			while (1){
				if (t == nullptr){
					break;
				}
				else{
					count++;
					t = t->next;
				}
			}
			return count;
		}
		return count;
	}
	bool search(int v) {
		if (head == nullptr && tail == nullptr) {
			return false;
		}
		else {
			node* t = head;
			while (t != nullptr) {
				if (t->data == v) {
					return true;
				}
				t = t->next;
			}
			return false;
		}
	}
	int sumeven() {
		int sum = 0;
		node* t = head;

		if (head == nullptr && tail == nullptr) {
			return 0;
		}
		else {
			while (t != nullptr) {
				if (t->data % 2 == 0) {
					sum += t->data;
				}
				t = t->next;
			}
		}
		return sum;
	}

	bool deleteNodeRecursive(node* curr, int v) {
		if (curr == nullptr) {
			cout << "Value not found" << endl;
			return false;
		}
		if (curr->data == v) {
			if (curr == head) {  // Case 1: Delete head
				cout << delathead();
			}
			else if (curr == tail) {  // Case 2: Delete tail
				cout << delattail();
			}
			else {  // Case 3: Delete a middle node
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				delete curr;
			}
			return true;
		}

		return deleteNodeRecursive(curr->next, v);
	}

	bool calldelval(int v) {
		if (head == nullptr) {  // Empty list check
			cout << "empty" << endl;
			return false;
		}
		return deleteNodeRecursive(head, v);
	}
	int countRecursive(node* t) {
		if (t == nullptr) return 0;
		return 1 + countRecursive(t->next);
	}

	int count() {
		return countRecursive(head);
	}
	bool add(dll obj2) {
		if (head == nullptr && tail == nullptr) {
			return false;
		}
		else {
			node* t = head;
			node* p = t->next;
			bool found = false;

			while (p != nullptr) {
				int sum = t->data + p->data;
				if (sum == 101) {
					cout << t->data << "," << p->data << endl;
					found = true;
					break;
				}
				else {
					t = t->next;
					p = p->next;
				}
			}

			if (!found) {
				return false;
			}
		}
		return true;
	}

	void sum(){
		node* t = head;
		int sum = 0;
		while (true){
			sum += t->data;
			t = t->next;
			if (t == head)
				break;
		}
		cout << "sum of all values are: " << sum << endl;
	}
	void sort(){
		for (node* i = head; i != head->prev; i = i->next){
			for (node*j = head; j != head->prev; j = j->next){
				if (j->next->data < j->data){
					swap(j->next->data, j->data);
				}
			}
		}
	}
	void delduplicate(){
		for (node* first = head; first != nullptr; first = first->next){
			node* second = first;
			while (second->next != nullptr) {
				if (first->data == second->next->data){
					node* t = second->next;
					second->next = t->next;
					if (t->next != nullptr){
						t->next->prev = second;
					}
					delete t;
					t = nullptr;

				}
				else{
					second = second->next;
				}
			}
		}
	}
	int maximum(){
		node* t = head;
		int max = t->data;
		while (t != nullptr){
			if (t->data > max){
				max = t->data;
			}
			t = t->next;
		}
		return max;
	}
	void secmaximum(){
		node* t = head;
		int max = t->data;
		int sec_max = t->data;
		while (t != nullptr){
			if (t->data > max){
				sec_max = max;
				max = t->data;
			}
			if (t->data > sec_max && max != t->data){
				sec_max = t->data;
			}
			t = t->next;
		}

		cout << "max is: " << max << endl;
		cout << "sec max is: " << sec_max << endl;
	}
	int fact(int n){
		if (n == 0){
			return 1;
		}
		if (n > 0){
			return n*fact(n - 1);
		}
	}
	void printfact(){
		node* t = head;
		while (t != nullptr){
			cout << "factorial of : " << t->data << " is: " << fact(t->data) << endl;
			t = t->next;
		}
	}

};
int main() {
	dll myList;
	int choice, value, position;

	do {
		cout << "\nMenu: " << endl;
		cout << "1. Insert Sorted" << endl;
		cout << "2. Search Value" << endl;
		cout << "3. Add nodes whose sum equals 101" << endl;
		cout << "4. Sum of Even Numbers" << endl;
		cout << "5. Count Nodes" << endl;
		cout << "6. Display from Head" << endl;
		cout << "7. Delete from tail" << endl;
		cout << "8. Remove Duplicates" << endl;
		cout << "9. Find Maximum Value" << endl;
		cout << "10. Find Second Maximum Value" << endl;
		cout << "11. Calculate Factorials of All Nodes" << endl;
		cout << "12. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to insert in sorted order: ";
			cin >> value;
			myList.insertsorted(value);
			break;
		case 2:
			cout << "Enter value to search: ";
			cin >> value;
			if (myList.search(value)) {
				cout << value << " found in the list." << endl;
			}
			else {
				cout << value << " not found in the list." << endl;
			}
			break;
		case 3:
			if (myList.add(myList)){
				cout << "Adding nodes where sum equals 101..." << endl;
			} // Add nodes where sum is 101
			else{
				cout << "no such numbers " << endl;
			}
			break;
		case 4:
			cout << "Sum of even numbers: " << myList.sumeven() << endl;
			break;
		case 5:
			cout << "Total nodes in the list: " << myList.count() << endl;
			break;
		case 6:
			cout << "Displaying list from head: ";
			myList.displayhead();
			cout << endl;
			break;
		case 7:
			cout << "Deleting all tail node..." << endl;
			myList.delattail();
			break;
		case 8:
			cout << "Removing duplicates..." << endl;
			myList.delduplicate();
			myList.displayhead();
			break;
		case 9:
			cout << "Maximum value in the list: " << myList.maximum() << endl;
			break;
		case 10:
			myList.secmaximum();
			break;
		case 11:
			cout << "Calculating factorials of all nodes:" << endl;
			myList.printfact();
			break;
		case 12:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 12);

	return 0;
}
