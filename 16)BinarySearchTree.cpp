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
	bst(const bst& other) {
		root = nullptr;
		copyTree(other.root);
	}
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
	void copyTree(node*otherRoot){
		if (otherRoot != nullptr) {
			insert(otherRoot->data); // Insert the data into the current tree
			copyTree(otherRoot->left); // Recursively copy the left subtree
			copyTree(otherRoot->rit); // Recursively copy the right subtree
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
	int max(int a, int b){
		if (a > b){
			return a;
		}
		else{
			return b;
		}
	}
	int height(node*p){
		if (p == nullptr){
			return 0;
		}
		else{
			return 1 + max(height(p->left), height(p->rit));
		}
	}
	void heightp(){
		if (root == nullptr){
			cout << "empty";

		}
		else{
			cout << height(root);
		}
	}
	bool identical(node* root1, node* root2) {
		if (root1 == nullptr && root2 == nullptr) {
			return true;
		}
		if (root1 == nullptr || root2 == nullptr) {
			return false;
		}
		if (root1->data != root2->data){
			return false;
		}
		if (root1->data == root2->data){
			return identical(root1->left, root2->left) &&
				identical(root1->rit, root2->rit);
		}
	}

	bool areIdentical(bst& other) {
		return identical(this->root, other.root); // Compare this->root with other.root

	}
	void callisBST(){
		cout << isBST(root);
	}
	bool isBST(node* root, node* minNode = nullptr, node* maxNode = nullptr) {
		if (root == nullptr) {
			return true;
		}
		if ((minNode != nullptr && root->data <= minNode->data) ||
			(maxNode != nullptr && root->data >= maxNode->data)) {
			return false;
		}

		return isBST(root->left, minNode, root) && isBST(root->rit, root, maxNode);
	}
	void balanced(){
		if (root == nullptr){
			cout << "empty";
		}
		else{
			int left = height(root->left);
			int rith = height(root->rit);
			if (left == rith){ cout << "balanced"; }
			else{
				cout << "not balanced";
			}
		}
	}
	node* findLCA(node* root, int n1, int n2) {
		if (!root) return nullptr;

		if (root->data > n1 && root->data > n2)
			return findLCA(root->left, n1, n2);  // Move left

		if (root->data < n1 && root->data < n2)
			return findLCA(root->rit, n1, n2); // Move right

		return root;  // Found LCA
	}
	int findDistanceFromRoot(node* root, int key) {
		int distance = 0;
		while (root) {
			if (root->data == key) return distance;
			else if (key < root->data) root = root->left;
			else root = root->rit;
			distance++;
		}
		return -1; // Should never happen if key exists
	}
	int findDistance(node* root, int n1, int n2) {
		node* lca = findLCA(root, n1, n2);
		if (!lca) return -1; // If LCA doesn't exist, nodes are not in BST

		int d1 = findDistanceFromRoot(lca, n1);
		int d2 = findDistanceFromRoot(lca, n2);

		return d1 + d2;
	}




};

int main() {
	bst tree;
	int choice, val, n1, n2;

	do {
		cout << "--- BST Operations Menu ---" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Height of Tree" << endl;
		cout << "3. Find Distance Between Two Nodes" << endl;
		cout << "4. Check if Balanced" << endl;
		cout << "5. Copy Tree" << endl;
		cout << "6. Check Identical Trees" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to insert: ";
			cin >> val;
			tree.insert(val);
			break;

		case 2:
			cout << "Height of BST: ";
			tree.heightp();
			cout << endl;
			break;

		case 3:
			cout << "Enter two node values: ";
			cin >> n1 >> n2;
			cout << "Distance between nodes: " << tree.findDistance(tree.root, n1, n2) << endl;
			break;

		case 4:
			tree.balanced();
			cout << endl;
			break;

		case 5: {
					bst copiedTree = tree;
					cout << "Tree copied successfully." << endl;
					copiedTree.print_inorder();
					break;
		}

		case 6: {
					bst otherTree;
					cout << "Insert values for another tree to compare (enter -1 to stop): ";

					while (true) {
						cin >> val;
						if (val == -1) break;
						otherTree.insert(val);
					}
					otherTree.deletev(-1);
					if (tree.areIdentical(otherTree))
						cout << "Trees are identical" << endl;
					else
						cout << "Trees are not identical" << endl;

					break;
		}

		case 7:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice! Try again." << endl;
		}

	} while (choice != 7);

	return 0;
}
