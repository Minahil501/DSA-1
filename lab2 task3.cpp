#include <iostream>
#include <string>
using namespace std;
class Book {
public:
	string name;
	string author;
	int pages;
	Book() {}
	Book(string n, string a, int p) : name(n), author(a), pages(p) {}
};

class Newspaper {
public:
	string name;
	string date;
	string edition;
	Newspaper() {}
	Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}
};

class Library {
private:
	Book books[75];
	Newspaper newspapers[75];
	int no_of_book;
	int no_of_newspaper;

public:
	Library() : no_of_book(0), no_of_newspaper(0) {}
	void addBook(const Book& b) {
		if (no_of_book < 100) {
			books[no_of_book++] = b;
		}
	}

	void addNewspaper(const Newspaper& n) {
		if (no_of_newspaper < 100) {
			newspapers[no_of_newspaper++] = n;
		}
	}

	void displayCollection() {
		cout << "Books are :" << endl;
		for (int i = 0; i < no_of_book; i++) {
			cout << "  " << books[i].name <<",author:"<< books[i].author << ", Pages: " << books[i].pages << endl;
		}

		cout << "Newspapers" << endl;
		for (int i = 0; i < no_of_newspaper; i++) {
			cout << "  " << newspapers[i].name << ", Date: " << newspapers[i].date << ", Edition: " << newspapers[i].edition << endl;
		}
	}

	void sortBooksByPages() {
		for (int i = 0; i < no_of_book - 1; i++) {
			for (int j = i + 1; j < no_of_book; ++j) {
				if (books[i].pages > books[j].pages) {
					swap(books[i], books[j]);
				}
			}
		}
	}

	void sortNewspapersByEdition() {
		for (int i = 0; i < no_of_newspaper - 1; i++) {
			for (int j = i + 1; j < no_of_newspaper; ++j) {
				if (newspapers[i].edition > newspapers[j].edition) {
					swap(newspapers[i], newspapers[j]);
				}
			}
		}
	}

	Book* searchBookByTitle(const string& title) {
		for (int i = 0; i < no_of_book; ++i) {
			if (books[i].name == title) {
				return &books[i];
			}
		}
		return nullptr; 
	}

	Newspaper* searchNewspaperByName(const string& name) {
		for (int i = 0; i < no_of_newspaper; ++i) {
			if (newspapers[i].name == name) {
				return &newspapers[i];

			}
		}
		return nullptr; 
	}
};

int main() {
	// Create book objects
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	// Create newspaper objects
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	// Create a library object
	Library library;

	// Add books and newspapers to the library
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	// Display the entire collection
	cout << "Before Sorting:\n";
	library.displayCollection();

	// Sort books by pages and newspapers by edition
	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	// Search for a book by title
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		cout << "  " << foundBook->name << " by " << foundBook->author << ", Pages: " << foundBook->pages << endl;
	}
	else {
		cout << "\nBook not found.\n";
	}

	// Search for a newspaper by name
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		cout << "  " << foundNewspaper->name << ", Date: " << foundNewspaper->date << ", Edition: " << foundNewspaper->edition << endl;
	}
	else {
		cout << "\nNewspaper not found.\n";
	}

	return 0;
}
