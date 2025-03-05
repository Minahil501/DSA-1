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
	bool delval(int v){
		if (head == nullptr&& tail == nullptr){//empty list case 1
			cout << "empty";
			return false;
		}
		if (v == head->data){ //boundary head case 2
			cout << delathead();
			return true;
		}
		if (v == tail->data){ //boundary tail case 3
			cout << delattail();
			return true;
		}
		else{ //mid somewhere
			node*t = head;
			while (1){
				if (t->data == v){
					break;
				}
				else{
					t = t->next;
				}
			}
			t->prev->next = t->next;
			t->next->prev = t->prev;
			delete t;
			t = nullptr;
			return true;
		}
	}
	int countRecursive(node* t) {
		if (t == nullptr) return 0;
		return 1 + countRecursive(t->next);
	}

	int count() {
		return countRecursive(head);
	}

bool deletetapos(int p){
		if (p == 1){ return delathead(); }
		if (p == count()){ return delattail(); }
		if (p > count()){ return false; }
		else {
			node*t = head;
			for (int i = 1; i < p; i++){
				t = t->next;
			}
			int v = t->data;
			delval(v);
			return true;
		}
	}
	
};
int main() {
    dll myList;
    int choice, value, pos;

    do {
        cout << "\nMenu: " << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Display from Head" << endl;
        cout << "4. Display from Tail" << endl;
        cout << "5. Delete at Head" << endl;
        cout << "6. Delete at Tail" << endl;
        cout << "7. Delete Node by Value" << endl;
        cout << "8. Delete Node at Position" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                myList.insertathead(value);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                myList.insertattail(value);
                break;
            case 3:
                cout << "Displaying from head: ";
                myList.displayhead();
                break;
            case 4:
                cout << "Displaying from tail: ";
                myList.displaytail();
                break;
            case 5:
                cout << "Deleting at head: ";
                myList.delathead();
                myList.displayhead();  // Display after deletion
                break;
            case 6:
                cout << "Deleting at tail: ";
                myList.delattail();
                myList.displayhead();  // Display after deletion
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.delval(value);
                cout<<endl;
                cout<<"after deletion"<<endl;
                myList.displayhead();  // Display after deletion
                break;
            case 8:
                cout << "Enter position to delete node: ";
                cin >> pos;
                if (myList.deletetapos(pos)) {
                    cout << "Node deleted at position " << pos << endl;
                } else {
                    cout << "Position out of bounds!" << endl;
                }
                myList.displayhead();  // Display after deletion
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}