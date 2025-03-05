#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<string, int> umap;
	string temp;

	cout << "Enter text (type 'END' to stop): " << endl;

	while (cin >> temp) {
		if (temp == "END")
			break;
		umap[temp]++;
	}
	int size = temp.length();
	cout << size;
	cout << "\nWord Frequency:\n";
	for (auto i : umap)
		cout << i.first << " " << (double)i.second/size<< endl;

	return 0;
}
