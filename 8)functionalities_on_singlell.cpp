#include<iostream>
#include<string>
using namespace std;
template <class t>
struct node {
	t data;
	node*next;
};
template <class t>
class list{
protected:
	node<t>* head;
	node<t>* tail;
public:
	list(){
		head = nullptr;
		tail = nullptr;
	}
	virtual void insert_at_head(t v) = 0;
	virtual void insert_at_tail(t v) = 0;
	virtual t del_at_head() = 0;
	virtual t del_at_tail() = 0;
	virtual void display() = 0;
};
template <class t>
class mylist :public list<t>{
public:
	int count;
	mylist() :list<t>(){ count = 0; }
	void insert_at_tail(int v){
		node<t>*nn = nullptr; // empty node created
		nn = new node<t>;
		nn->data = v; //put value
		nn->next = nullptr; //one node successfully created
		if (head == nullptr&&tail == nullptr){ //single
			head = nn;
			tail = nn;
		}
		else{
			tail->next = nn;
			tail = nn;
		}
		count++;
	}
	void insert_at_head(int v){
		node<t>*nn = nullptr; // empty node created
		nn = new node<t>;
		nn->data = v;
		nn->next = nullptr;
		if (head == nullptr && tail == nullptr){ 
			head = nn;
			tail = nn;
		}
		else{
			nn->next = head;
			head = nn;

		}
		count++;
	}
	void display(){
		node<t>*temp = head;
		while (1){
			cout << temp->data << " ";
			temp = temp->next;
			if (temp == nullptr){
				break;
			}
		}
		cout << endl;
	}
	int count1(){
		return count;
	}
	bool search(int key) {
		node<t>* temp = head;
		while (1) {
			if (temp->data == key) {
				return true; // Key found
			}
			temp = temp->next;
			if (temp == nullptr){
				break;
			}
		}
		return false; // Key not found
	}
	t del_at_head(){
		if (head == nullptr&& tail == nullptr){ //empty
			cout << "empty";
			return NULL;
		}
		else if (head == tail){
			t returningvalue = head->data;
			delete head;
			head = nullptr;
			tail = nullptr;
			return returningvalue;

		}
		else{
			t returningvalue = head->data;
			node<t>* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
			return returningvalue;
		}
	}
	t del_at_tail(){
		if (head == nullptr&& tail == nullptr){ //empty
			cout << "empty";
			return NULL;
		}
		else if (head == tail){
			t returningvalue = head->data;
			delete head;
			head = nullptr;
			tail = nullptr;
			return returningvalue;
		}
		else {
			t returningvalue = tail->data;
			node<t>*temp = head;
			while (1){
				if (temp->next->next == nullptr){
					break;
				}
				else{
					temp = temp->next;
				}
			}
			delete tail;
			tail = temp;
			tail = nullptr;
			temp->next = nullptr;
			return returningvalue;
		}
	}
	void insert_sorted(int v){
		if (head == nullptr&& tail == nullptr){ //empty to single
			node<t>*nn = new node<t>;
			nn->data = v;
			nn->next = nullptr;
			head = nn;
			tail = nn;
		}
		else if (v <= head->data){
			insert_at_head(v);
		}
		else if (v >= tail->data){
			insert_at_tail(v);
		}
		else{
			node<t>*nn = new node<t>;
			nn->data = v;
			nn->next = nullptr;
			node<t>*temp = head;
			while (1){
				if (temp->data < v && temp->next->data >= v){
					break;
				}
				else{
					temp = temp->next;
				}
			}
			nn->next = temp->next;
			temp->next = nn;
		}
	}
	bool isempty(){
		return (head == nullptr&& tail == nullptr);
	}
	int peek(){
		return head->data;
	}
	int top(){
		return tail->data;
	}
	template <typename t>
	void odd(mylist<t>& l2) {
		int sum = 0;
		node<t>* current = head; // Use the head pointer to traverse the list
		while (current != nullptr) {
			if (current->data % 2 != 0) { // Check if the number is odd
				sum += current->data;
			}
			current = current->next;
		}

		cout << "Sum of odd numbers: " << sum << endl; // Print the total sum of odd numbers
	}
	template <typename t>
	void max(mylist<t>& l2) {
		t max = head->data; // Initialize max with the first element
		node<t>* current = head; // Start traversing from the head
		while (current != nullptr) {
			if (current->data > max) { // Update max if the current value is greater
				max = current->data;
			}
			current = current->next; // Move to the next node
		}

		cout << "Maximum value in the list: " << max << endl; // Print the maximum value
	}
};

template <typename t>
void myreverse(mylist<t>& l2) {
	mylist<t> l1;
	while (!l2.isempty()) {
		l1.insert_at_head(l2.del_at_head());
	}
	while (!l1.isempty()) {
		l2.insert_at_tail(l1.del_at_head());
	}
	l2.display(); // Display the reversed list
}
void merge(mylist<int>&l1, mylist<int>&l2){
	mylist<int>l3;
	cout << "merged list is " << endl;
	while (!l1.isempty()){
		l3.insert_sorted(l1.del_at_head());
	}
	while (!l2.isempty()){
		l3.insert_sorted(l2.del_at_head()); //it includes duplicates as well
	}
	l3.display();
}
#include <iostream>
using namespace std;

int main() {
	int choice, value;
	mylist<int> m1;

	do {
		cout << "1. INSERT SORTED" << endl;
		cout << "2. DISPLAY" << endl;
		cout << "3. COUNT ELEMENTS" << endl;
		cout << "4. SUM OF ODD NUMBERS" << endl;
		cout << "5. MAX ELEMENT" << endl;
		cout << "6. MERGE LISTS" << endl;
		cout << "7. REVERSE LIST" << endl;
		cout << "8. SEARCH ELEMENT" << endl;
		cout << "9. EXIT" << endl;
		cout << "ENTER CHOICE: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "ENTER VALUE: " << endl;
			cin >> value;
			m1.insert_sorted(value);
			break;
		case 2:
			m1.display();
			cout << endl;
			break;
		case 3:
			cout << "TOTAL ELEMENTS: " << m1.count1()+1 << endl;
			break;
		case 4:
			m1.odd(m1);
			break;
		case 5:
			m1.max(m1);
			break;
		case 6: {
					mylist<int> m2;
					int size;
					cout << "ENTER VALUES FOR SECOND LIST (END WITH -1): ";
					while (true) {
						cin >> value;
						if (value == -1) break;
						m2.insert_sorted(value);
					}
					merge(m1, m2);
					break;
		}
		case 7:
			myreverse(m1);
			break;
		case 8:
			cout << "ENTER VALUE TO SEARCH: ";
			cin >> value;
			if (m1.search(value)) {
				cout << "ELEMENT FOUND" << endl;
			}
			else {
				cout << "ELEMENT NOT FOUND" << endl;
			}
			break;
		case 9:
			cout << "EXITING..." << endl;
			break;
		default:
			cout << "INVALID CHOICE" << endl;
		}
	} while (choice != 9);

	return 0;
}
