#include <iostream>
using namespace std;
struct node{
	int data;
	node*prev;
	node*next;
};
using namespace std;
class doublell{
protected:
	node*head;
	node*tail;
public:
	doublell(){
		head = nullptr;
		tail = nullptr;
	}
	virtual void insertathead(int value) = 0;
	virtual void  insertattail(int value) = 0;
	virtual bool isempty() = 0;
	virtual void insertRecursive(node* current, int position, int value, int currentposition) = 0;
	virtual void insertAtPosition(int position, int value) = 0;//helper
	virtual void printListRecursive(node* current) = 0;
	virtual void printList() = 0;//helper

};
class mydcll :public doublell{
public:
	mydcll() :doublell(){}
	void insertathead(int value){
		node*nn = new node;
		nn->data = value;
		nn->prev = nullptr;
		nn->next = nullptr;
		if (head == nullptr&&tail == nullptr){
			head = nn;
			tail = nn;
			nn->prev = nn;
			nn->next = nn;
		}
		else{
			nn->next = head;
			head->prev = nn;
			head = nn;
			head->prev = tail;
			tail->next = head;
		}
	}
	void insertattail(int value){
		node*nn = new node;
		nn->data = value;
		nn->prev = nullptr;
		nn->next = nullptr;
		if (head == nullptr && tail == nullptr){
			head = nn;
			tail = nn;
			nn->prev = nn;
			nn->next = nn;
		}
		else{
			tail->next = nn;
			nn->prev = tail;
			tail = nn;
			tail->next = head;
			head->prev = tail;
		}
	}
	bool isempty(){
		return (head == nullptr && tail == nullptr);
	}
	void display(){
		if (head == nullptr && tail == nullptr)
			cout << "LL is empty" << endl;
		else
		{
			node* t = head;
			while (true)
			{
				cout << t->data << endl;
				t = t->next;
				if (t == head)
					break;
			}
		}
	}
	void printListRecursive(node* current) {
		cout << current->data << " ";
		if (current->next != head) {
			printListRecursive(current->next);
		}
	}
	void printList() { //helper
		if (!isempty()) {
			printListRecursive(head);
		}
	}
	void insertRecursive(node* current, int position, int value, int currentposition = 1) {
		if (current->next == head) { //base
			cout << "end of list" << endl;
			insertattail(value);
			return;
		}
		if (currentposition == position - 1) {
			node* nn = new node;
			nn->data = value;
			nn->next = current->next;
			nn->prev = current;
			current->next->prev = nn;
			current->next = nn;
			return;
		}

		insertRecursive(current->next, position, value, currentposition + 1);
	}
	void insertAtPosition(int position, int value) {
		if (position < 1) {
			cout << "invalid position" << endl;
		}
		if (position == 1) {
			insertathead(value);
		}
		else {
			insertRecursive(head, position, value);
		}
	}
};
int main() {
	mydcll list;
	int choice, position, value;
	while (1) {
		cout << "menu: " << endl;
		cout << "1. insert at position" << endl;
		cout << "2. print list" << endl;
		cout << "3. exit" << endl;
		cout << "enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "enter position: ";
			cin >> position;
			cout << "enter value: ";
			cin >> value;
			list.insertAtPosition(position, value);
			break;
		case 2:
			list.printList();
			break;
		case 3:
			cout << "exiting program." << endl;
			return 0;
		default:
			cout << "invalid choice, please try again." << endl;
		}
	}

	return 0;
}