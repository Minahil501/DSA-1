struct TrieNode {
	bool terminalnode;
	TrieNode* children[52];
	TrieNode() {
		terminalnode = false;
		for (int i = 0; i < 52; i++) {
			children[i] = nullptr;
		}
	}
};
#include <iostream>
#include <string>
using namespace std;
class Trie{
protected:
	TrieNode* root;
	Trie() {
		root = new TrieNode();
	}
private:
	virtual void insert_recursively(TrieNode*, string&) = 0;
	virtual void inorder(TrieNode*, const string&) = 0;
	virtual bool search_recursively(TrieNode*, string&) = 0;
	virtual TrieNode* delete_recursively(TrieNode*, string&, bool&, int depth = 0) = 0;
	virtual int countWords(TrieNode*) = 0;
	virtual bool isEmpty(TrieNode*) = 0;
	virtual void findLongestWord(TrieNode*, string, string&) = 0;
	virtual void findshortestword(TrieNode*, string, string&) = 0;
	virtual bool findPalindromes(TrieNode*, string, bool&) = 0;
	virtual int findHeight(TrieNode*) = 0;
	virtual bool checkPrefix(TrieNode*, string&, int&) = 0;
	virtual void findSuggestions(TrieNode*, string) = 0;
public:
	virtual void call_insert(string&) = 0;
	virtual void print() = 0;
	virtual bool call_search(string&) = 0;
	virtual void call_delete(string&) = 0;
	virtual bool call_isEmpty() = 0;
	virtual int call_count() = 0;
	virtual	string call_findLongestWord() = 0;
	virtual	string call_findshortestWord() = 0;
	virtual	void call_findPalindromes() = 0;
	virtual	void call_checkPrefix(string&) = 0;
	virtual	int call_findHeight() = 0;
	virtual	void call_autosuggest(string&) = 0;
	virtual	void menu() = 0;
};
class myTrie :public Trie {
private:
	// Calculate index
	int calculate_index(string& word) {
		char c = word[0];
		int index;
		if (c >= 'a' && c <= 'z') {
			index = c - 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			index = c - 'A' + 26;
		}
		else { // if alphabets are not 
			index = -1;
		}
		return index;
	}
	// Insertion
	void insert_recursively(TrieNode* root, string& word) {
		if (word.length() == 0) {
			root->terminalnode = true;
			return;
		}
		int index = calculate_index(word);
		if (index == -1) { //for non alphabetical characters
			insert_recursively(root, word.substr(1));
			return;
		}
		if (root->children[index] == nullptr) {
			root->children[index] = new TrieNode();
		}
		insert_recursively(root->children[index], word.substr(1));
	}
	// display
	void inorder(TrieNode* temp, const string& word) {
		if (isEmpty(root)){ cout << "no word trie is empty" << endl; }
		else{
			if (temp->terminalnode) {
				cout << word << endl;
			}
			for (int i = 0; i < 52; i++) {
				if (temp->children[i]) {
					char index;
					if (i < 26) {
						index = 'a' + i;
					}
					else {
						index = 'A' + (i - 26);
					}
					inorder(temp->children[i], word + index);
				}
			}
		}
	}

	//search
	bool search_recursively(TrieNode* root, string& word) {
		if (word.length() == 0) {
			return root->terminalnode;
		}
		int index = calculate_index(word);
		if (index == -1) { // for non alphabetical strings
			return false;
		}
		if (root->children[index] == nullptr) {
			return false;
		}

		return search_recursively(root->children[index], word.substr(1));
	}
	//deletion
	TrieNode* delete_recursively(TrieNode* root, string& word, bool& wordFound, int depth = 0) {
		if (root == nullptr) {
			return nullptr;
		}
		if (depth == word.length()) {
			if (root->terminalnode) {
				root->terminalnode = false;
				wordFound = true;
			}
			if (isEmpty(root)) {
				delete root;
				root = nullptr;
			}

			return root;
		}
		char c = word[depth];
		int index;
		if (c >= 'a' && c <= 'z') {
			index = c - 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			index = c - 'A' + 26;
		}
		else {
			return root;
		}
		root->children[index] = delete_recursively(root->children[index], word, wordFound, depth + 1);
		if (isEmpty(root) && !root->terminalnode) {
			delete root;
			root = nullptr;
		}
		return root;
	}
	//count
	int countWords(TrieNode* root) {
		if (root == nullptr){ return 0; };
		int count = root->terminalnode;
		for (int i = 0; i < 52; i++) {
			count += countWords(root->children[i]);
		}
		return count;
	}


	//empty
	bool isEmpty(TrieNode* root) {
		if (root == nullptr) {
			return true;
		}
		for (int i = 0; i < 52; i++) {
			if (root->children[i] != nullptr) {
				return false;
			}
		}
		return true;
	}

	//longest word
	void findLongestWord(TrieNode* root, string currentWord, string& longestWord) {
		if (root == nullptr) return;
		if (root->terminalnode) {
			if (currentWord.length() > longestWord.length()) {
				longestWord = currentWord;
			}
			else if (currentWord.length() == longestWord.length()) {
				if (currentWord < longestWord) {
					longestWord = currentWord;
				}
			}
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i] != nullptr) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				findLongestWord(root->children[i], currentWord + c, longestWord);
			}
		}
	}


	//shortest word
	void findshortestword(TrieNode* root, string currentWord, string& shortestWord) {
		if (root == nullptr) {
			return;
		}
		if (root->terminalnode) {
			if (shortestWord.empty()) {
				shortestWord = currentWord;
			}
			else if (currentWord.length() < shortestWord.length()) {
				shortestWord = currentWord;
			}
			else if (currentWord.length() == shortestWord.length()) {
				if (currentWord < shortestWord) {
					shortestWord = currentWord;
				}
			}
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i] != nullptr) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				findshortestword(root->children[i], currentWord + c, shortestWord);
			}
		}
	}

	//palindrome
	bool isPalindrome(string& word) {
		int left = 0, right = word.length() - 1;
		while (left < right) {
			if (word[left] != word[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	bool findPalindromes(TrieNode* root, string currentWord, bool& foundPalindrome) {
		if (root == nullptr) return false;
		if (root->terminalnode && isPalindrome(currentWord)) {
			cout << "Yes!  " << currentWord << endl;
			foundPalindrome = true;
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i]) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				findPalindromes(root->children[i], currentWord + c, foundPalindrome);
			}
		}
		return foundPalindrome;
	}
	//height of trie
	int max(int a, int b){
		if (a > b){ return a; }
		else { return b; }
	}
	int findHeight(TrieNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int maxHeight = 0;
		for (int i = 0; i < 52; i++) {
			if (root->children[i]) {
				maxHeight = max(maxHeight, findHeight(root->children[i]));
			}
		}
		return maxHeight + 1;
	}
	//prefix
	bool checkPrefix(TrieNode* root, string& prefix, int& count) {
		TrieNode* currentNode = root;
		string currentWord = prefix;
		for (unsigned int i = 0; i < prefix.length(); ++i) {
			char c = prefix[i];
			int index;
			if (c >= 'a' && c <= 'z') {
				index = c - 'a';
			}
			else if (c >= 'A' && c <= 'Z') {
				index = c - 'A' + 26;
			}
			else {
				return false;
			}
			if (currentNode->children[index] == nullptr) {
				return false;
			}
			currentNode = currentNode->children[index];
		}

		printWordsWithPrefix(currentNode, currentWord, count);
		return true;
	}

	void printWordsWithPrefix(TrieNode* node, string currentWord, int& count) {
		if (node->terminalnode) {
			cout << "Word with prefix found: \"" << currentWord << "\"" << endl;
			count++;
			cout << "Count: " << count << endl;
		}
		for (int i = 0; i < 52; ++i) {
			if (node->children[i] != nullptr) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				printWordsWithPrefix(node->children[i], currentWord + c, count);
			}
		}
	}
	//auto
	void findSuggestions(TrieNode* node, string prefix) {
		if (node == nullptr) return;
		if (node->terminalnode) {
			cout << prefix << endl;
		}
		for (int i = 0; i < 52; ++i) {
			if (node->children[i]) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				findSuggestions(node->children[i], prefix + c);
			}
		}
	}
	void autoSuggestions(TrieNode* root, string& prefix) {
		TrieNode* node = root;
		int count = 0;
		if (checkPrefix(root, prefix, count)) {
			cout << "Suggestions for prefix \"" << prefix << "\":" << endl;
			findSuggestions(node, prefix);
		}
		else {
			cout << "No suggestions found!" << endl;
		}
	}
public:
	myTrie() :Trie(){}
	void call_insert(string& word) {
		insert_recursively(root, word);
	}
	void print() {
		inorder(root, "");
	}
	bool call_search(string& word) {
		return search_recursively(root, word);
	}
	void call_delete(string& word) {
		bool wordFound = false;
		root = delete_recursively(root, word, wordFound, 0);
		if (!wordFound) {
			cout << "Cannot delete word: \"" << word << "\" because it is not present in the Trie." << endl;
		}
		else {
			cout << "Word \"" << word << "\" has been deleted from the Trie." << endl;
		}
	}
	bool call_isEmpty() {
		return isEmpty(root);
	}
	int call_count() {
		return countWords(root);
	}

	string call_findLongestWord() {
		string longestWord = "", currentWord = "";
		findLongestWord(root, currentWord, longestWord);
		return longestWord;
	}
	string call_findshortestWord() {
		string shortestWord = "", currentword = "";
		findshortestword(root, currentword, shortestWord);
		return shortestWord;
	}
	void call_findPalindromes() {
		bool foundPalindrome = false;
		if (!findPalindromes(root, "", foundPalindrome)) {
			cout << "No palindrome in trie" << endl;
		}
	}
	void call_checkPrefix(string& prefix) {
		int count = 0;

		if (checkPrefix(root, prefix, count)) {
			cout << "Prefix \"" << prefix << "\" found" << endl;
		}
		else {
			cout << "Prefix not found" << endl;
		}
	}
	int call_findHeight() {
		return findHeight(root) - 1;
	}
	void call_autosuggest(string& prefix){
		autoSuggestions(root, prefix);
	}

	void menu() {
		cout << "========================" << endl;
		cout << "  TRIE FUNCTIONALITIES " << endl;
		cout << "========================" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Inorder Display" << endl;
		cout << "5. Check if Empty" << endl;
		cout << "6. Count Words" << endl;
		cout << "7. Find Longest Word" << endl;
		cout << "8. Find Shortest Word" << endl;
		cout << "9. Find Palindromes" << endl;
		cout << "10. Find Height" << endl;
		cout << "11. Search a Prefix" << endl;
		cout << "12. Auto suggestion" << endl;
		cout << "13. Exit" << endl;
		cout << "Enter your choice: ";
	}
};
int main() {
	myTrie t;
	int choice;
	string input;
	string prefix;
	while (true) {
		t.menu();
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter a word to insert: ";
			cin >> input;
			t.call_insert(input);
			cout << "!!!Word inserted successfully!!!" << endl;
			break;
		case 2:
			cout << "Enter a word to search: ";
			cin >> input;
			if (t.call_search(input)) {
				cout << "!!!Word found!!!" << endl;
			}
			else {
				cout << "!!!Word not found!!!" << endl;
			}
			break;
		case 3:
			cout << "Enter a word to delete: ";
			cin >> input;
			t.call_delete(input);
			break;
		case 4:
			cout << "Words in the Trie:" << endl;
			t.print();
			break;
		case 5:
			if (t.call_isEmpty()) {
				cout << "Trie is empty." << endl;
			}
			else {
				cout << "Trie is not empty." << endl;
			}
			break;
		case 6:
			cout << "Total number of words: " << t.call_count() << endl;
			break;
		case 7:
			cout << "Longest word: " << t.call_findLongestWord() << endl;
			break;
		case 8:
			cout << "Shortest word: " << t.call_findshortestWord() << endl;
			break;
		case 9:
			cout << "Is There A Palindrome?" << endl;
			t.call_findPalindromes();
			break;
		case 10:
			cout << "Height of the Trie: " << t.call_findHeight() << endl;
			break;
		case 11:
			cout << "Enter prefix to search" << endl;
			cin >> prefix;
			t.call_checkPrefix(prefix);
			break;
		case 12:
			cout << "Enter a word to auto suggest ";
			cin >> prefix;
			t.call_autosuggest(prefix);
			break;
		case 13:
			cout << "Exiting program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}

	return 0;
}