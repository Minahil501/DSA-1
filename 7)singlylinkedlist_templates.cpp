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
};
int main() {
	int choice, value, size;
	mylist<int> m1;

	do {
		cout << "1. INSERT AT HEAD" << endl;
		cout << "2. INSERT AT TAIL" << endl;
		cout << "3. DELETE AT HEAD" << endl;
		cout << "4. DELETE AT TAIL" << endl;
		cout << "5. DISPLAY" << endl;
		cout << "6. FIRST ELEMENT" << endl;
		cout << "7. LAST ELEMENT" << endl;
		cout << "8. NO OF NODES" << endl;
		cout << "9. EXIT" << endl;
		cout << "ENTER CHOICE: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "ENTER VALUE: " << endl;
			cin >> value;
			m1.insert_at_head(value);
			break;
		case 2:
			cout << "ENTER VALUE: " << endl;
			cin >> value;
			m1.insert_at_tail(value);
			break;
		case 3:
			cout << "DELETED HEAD: " << m1.del_at_head() << endl;
			break;
		case 4:
			cout << "DELETED TAIL: " << m1.del_at_tail() << endl;
			break;
		case 5:
			m1.display();
			cout << endl;
			break;
		case 6:
			cout << "FIRST ELEMENT: " << m1.peek() << endl;
			break;
		case 7:
			cout << "LAST ELEMENT: " << m1.top() << endl;
			break;
		case 8:
			cout << "NO OF NODES ARE: " << m1.count1() << endl;
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



