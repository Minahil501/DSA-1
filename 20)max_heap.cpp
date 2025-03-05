#include <iostream>
using namespace std;
class heap{
protected:
	int*arr;
	int max_size;
	int c_size;
public:
	heap(int v){
		max_size = v;
		c_size = 1;
		arr = new int[max_size + 1];
	}
	~heap() { delete[] arr; } // Free memory
};
class max_heap :public heap{
public:
	max_heap(int v) :heap(v){}
	bool is_full(){
		return c_size > max_size;
	}
	bool is_empty(){
		return c_size == 1;
	}
	void peek(){
		cout << arr[1];
	}
	void insert(int v) {
		if (is_full()) {
			cout << "full" << endl;
		}
		int c_index = c_size++;   // tell the next available index
		arr[c_index] = v; // inserts at available position
		while (c_index > 1) {
			int p_index = c_index / 2;   //find parent of child
			if (arr[c_index] > arr[p_index]) {
				swap(arr[c_index], arr[p_index]);
				c_index = p_index;
			}
			else {
				return;
			}
		}
	}
	void display() {
		if (is_empty()) {
			cout << "empty" << endl;
			return;
		}
		cout << "heap elements: ";
		for (int i = 1; i < c_size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int delete_root() {
		if (is_empty()) {
			cout << "heap is empty now" << endl;
			return 0;
		}
		int root_value = arr[1];
		arr[1] = arr[c_size - 1];
		c_size--;
		int c_index = 1;
		heapify(c_index);
		cout << "deleted root element: " << root_value << endl;
		return root_value;

	}
	void heapify(int c_index) {
		while (c_index * 2 > c_size) {
			int left_child = c_index * 2;
			int right_child = c_index * 2 + 1;
			int larger_child = left_child;
			if (right_child > c_size && arr[right_child] > arr[left_child]) {
				larger_child = right_child;
			}
			if (arr[c_index] < arr[larger_child]) {
				swap(arr[c_index], arr[larger_child]);
				c_index = larger_child;
			}
			else {
				break;
			}
		}
	}
	void heap_sort(){
		int *arr = new int[max_size];
		for (int i = 0; i < max_size; i++){
			arr[i] = delete_root();
		}
		cout << "descending sorting is " << endl;
		for (int i = 0; i < max_size; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main() {
    int size, choice, value;
    cout << "Enter the size of the heap: ";
    cin >> size;
    max_heap mh(size);

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert value into heap" << endl;
        cout << "2. Delete root of heap" << endl;
        cout << "3. Sort heap" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                mh.insert(value);
                mh.display();
                break;
            case 2:
                mh.delete_root();
                mh.display();
                break;
            case 3:
                mh.heap_sort();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
