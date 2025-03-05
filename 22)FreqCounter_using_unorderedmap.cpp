//#include <iostream>
//#include <fstream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<string, int> umap;
//
//	*ifstream in;
//	in.open("text.txt");
//	string temp;
//
//	while (!in.eof())
//	{
//		in >> temp;
//		umap[temp]++;
//	}
//
//	for (auto i : umap)
//		cout << i.first << " " << i.second << endl;
//
//
//	return 0;
//}
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

	cout << "\nWord Frequency:\n";
	for (auto i : umap)
		cout << i.first << " " << i.second << endl;

	return 0;
}
