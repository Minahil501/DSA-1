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
class queue{
public:
	mylist<int> l;
	void enqueue(int t){
		l.insert_at_tail(t);
	}
	int dequeue(){
		return l.del_at_head();
	}
	void display(){
		l.display();
	}
	int front(){
		int returning_value = l.del_at_head();
		l.insert_at_head(returning_value);
		return returning_value;
	}
	bool isempty(){
		return l.del_at_head() == NULL;
	}

};
int main() {
	queue q;
	int choice, value;
	do {
		cout << "Menu:" << endl;
		cout << "1. Enqueue an element into the queue" << endl;
		cout << "2. Dequeue an element from the queue" << endl;
		cout << "3. Display the front element of the queue" << endl;
		cout << "4. Display all elements in the queue" << endl;
		cout << "5. Check if the queue is empty" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the value to enqueue: ";
			cin >> value;
			q.enqueue(value);
			break;
		case 2:
			cout << "Dequeued value: " << q.dequeue() << endl;
			break;
		case 3:
			cout << "Front element: " << q.front() << endl;
			break;
		case 4:
			q.display();
			break;
		case 5:
			if (q.isempty()){
			}
			else {
				cout << "not empty" << endl;
			}
			break;
		case 6:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice, please try again." << endl;
		}
	} while (choice != 6);

	return 0;
}



