#include <iostream>
using namespace std;
struct node{
	int data;
	node*rit;
	node*left;
};
class tree{
public:
	node*root;
	tree(){
		root == nullptr;
	}
	virtual void insert(int v) = 0;
	virtual void inorder(node*) = 0;

};
class bst : public tree{
public:
	bst() :tree(){}
	void insert(int v){
		node*nn = new node;
		nn->data = v;
		nn->left = nullptr;
		nn->rit = nullptr;
		if (root == nullptr){
			root = nn;
		}
		else {
			node*t = root;
			while (1){
				if (v < t->data){//left
					if (t->left == nullptr){
						t->left = nn;
						break;
					}
					else {
						t = t->left;
					}

				}
				if (v>t->data){//rit
					if (t->rit == nullptr){
						t->rit = nn;
						break;
					}
					else{
						t = t->rit;
					}

				}
			}
		}
	}
	void inorder(node*p){
		if (p != nullptr){
			inorder(p->left);
			cout << p->data;
			inorder(p->rit);
		}
	}
	void print_inorder(){
		if (root != nullptr){
			inorder(root);
		}
		else{

			cout << "empty";
		}
	}
	void preorder(node*p){
		if (p != nullptr){
			cout << p->data;
			preorder(p->left);
			preorder(p->rit);
		}
	}
	void print_preorder(){
		if (root != nullptr){
			preorder(root);
		}
		else{

			cout << "empty";
		}
	}
	void postorder(node*p){
		if (p != nullptr){
			postorder(p->left);
			postorder(p->rit);
			cout << p->data;
		}
	}
	void print_postorder(){
		if (root != nullptr){
			postorder(root);
		}
		else{

			cout << "empty";
		}
	}
	void copy(node*root, int arr[], int&index){
		if (root == nullptr){
			return;
		}
		else{
			copy(root->left, arr, index);
			arr[index++] = root->data;
			copy(root->rit, arr, index);
		}
	}

	int deletev(int value){
		{
			if (root == nullptr)
			return false;

			else if (root->left == nullptr && root->rit == nullptr) //single node case
			{
				if (root->data == value)
				{
					delete root;
					root = nullptr;
					return true;
				}

				else
					return false;
			}
			else
			{
				node* p = root;
				node* c = root;

				while (1)
				{
					if (c == nullptr)
						return false;

					if (c->data == value)
					{
						break;
					}

					if (value > c->data)
					{
						p = c;
						c = c->left;
					}

					else
					{
						p = c;
						c = c->rit;
					}


				}

				//cout << p->data << endl;
				//cout << c->data << endl;
				//while (1);

				if (c->left != nullptr && c->rit != nullptr)
				{
					//2 children
					node* t = c;

					p = c;
					c = c->rit;

					while (1)
					{

						if (c->left == nullptr)
						{
							t->data = c->data;
							value = c->data;
							break;
						}
						else
						{
							p = c;
							c = c->left;
						}
					}
				}



				//leaf node deletion:
				if (c->left == nullptr && c->rit == nullptr)
				{
					if (c->data > p->data) // left child of parent
					{
						delete c;
						c = nullptr;
						p->left = nullptr;
					}

					else //right child of parent
					{
						delete c;
						c = nullptr;
						p->rit = nullptr;
					}

					return true;
				}

				else if (c->left != nullptr && c->rit == nullptr)
				{
					if (c->data > p->data) //leftChild of parent
					{
						p->left = c->left;
						delete c;
						c = nullptr;
						return true;
					}

					else //right child of parent
					{
						p->rit = c->left;
						delete c;
						c = nullptr;
						return true;
					}
				}

				else if (c->left == nullptr && c->rit != nullptr)
				{
					if (c->data > p->data) //leftChild of parent
					{
						p->left = c->rit;
						delete c;
						c = nullptr;
						return true;
					}

					else //right child of parent
					{
						p->rit = c->left;
						delete c;
						c = nullptr;
						return true;
					}

				}
			}

		}
	}
};
int main() {
	bst myTree;
	int choice, value;

	do {
		cout << "Menu: " << endl;
		cout << "1. Insert Value" << endl;
		cout << "2. Print Inorder" << endl;
		cout << "3. Print Preorder" << endl;
		cout << "4. Print Postorder" << endl;
		cout << "5. Delete Value" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to insert: ";
			cin >> value;
			myTree.insert(value);
			break;
		case 2:
			cout << "Inorder Traversal: ";
			myTree.print_inorder();
			break;
		case 3:
			cout << "Preorder Traversal: ";
			myTree.print_preorder();
			break;
		case 4:
			cout << "Postorder Traversal: ";
			myTree.print_postorder();
			break;
		case 5:
			cout << "Enter value to delete: ";
			cin >> value;
			if (myTree.deletev(value)) {
				cout << value << " deleted." << endl;
			}
			else {
				cout << value << " not found." << endl;
			}
			break;
		case 6:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 6);

	return 0;
}