/* Author:Seth McCrudden
* Last date modified: 24-Oct-2020
* File name: books.cpp
* Description: Implementation of the inventory class defined in books.h.
*/
#include "books.h"

books::books() {
	maxBookLength = 10;
}

books::~books() {
	this->bookList.clear();
	maxBookLength = 10;
}

int books::compareBookNames(const std::string& first, const std::string& second) {
	int smallestSize = first.length() > second.length() ? second.length() : first.length();
	for (int i = 0; i < smallestSize; i++) {
		unsigned char firstChar = first[i];
		// Turns firstChar to lower case
		if (firstChar >= 'A' && firstChar <= 'Z') {
			firstChar += 32;
		}
		unsigned char secondChar = second[i];
		// Turns secondChar to lower case
		if (secondChar >= 'A' && secondChar <= 'Z') {
			secondChar += 32;
		}
		if (firstChar < secondChar) {
			return -1;
		}
		else if (secondChar < firstChar) {
			return 1;
		}
	}
	return 0;
}

void books::insert_sorted(const book& bookToAdd) {
	if (bookToAdd.title.length() > this->maxBookLength) {
		this->maxBookLength = bookToAdd.title.length();
	}
	for (std::list<book>::iterator it = this->bookList.begin(); true; it++) {
		if (it == this->bookList.end()) {
			this->bookList.push_back(bookToAdd);
			break;
		}
		// if equals one bookToAdd should be before it->title
		else if (this->compareBookNames(it->title, bookToAdd.title) == 1) {
			bookList.insert(it, bookToAdd);
			break;
		}
	}
}

bool books::read_from_file(const std::string& fileName) {
	this->bookList.clear();
	this->maxBookLength = 10;
	std::ifstream file(fileName);
	if (!file.is_open()) {
		return false;
	}
	int i = 0;
	book currBook;
	for (std::string line; std::getline(file, line); i++) {
		if (i % 4 == 0) {
			currBook.title = line;
		}
		else if (i % 4 == 1) {
			currBook.price = stod(line);
		}
		else if (i % 4 == 2) {
			currBook.ISBN = line;
		}
		else {
			currBook.stock = std::stoi(line);
			insert_sorted(currBook);
		}
	}
	if (i % 4 > 0) {
		currBook.stock = 0;
		if (i % 4 == 2) {
			currBook.ISBN = "";
		} else if (i % 4 == 1) {
			currBook.price = 0;
		}
		insert_sorted(currBook);
	}
	file.close();
	return true;
}

bool books::write_to_file(const std::string& fileName) {
	// ios::binary is important to prevent windows from adding \r before new lines
	// which will cause issues when running on linux
	std::ofstream file(fileName, std::ios::binary);
	if (!file.is_open()) {
		return false;
	}
	for (std::list<book>::iterator it = this->bookList.begin(); it != this->bookList.end(); it++) {
		file << it->title << "\n";
		file << it->price << "\n";
		file << it->ISBN << "\n";
		file << it->stock << "\n";
	}
	file.close();
	return true;
}

void books::lookup(const std::string& bookName) {
	using namespace std;
	cout << fixed << left << setprecision(2);
	cout << '|' << setfill('-') << setw(maxBookLength) << '-' << '|' << setw(MAX_PRICE_LENGTH) << '-' << '|' << setw(MAX_ISBN_LENGTH) << '-' << '|' << setw(MAX_QUANTITY_LENGTH) << '-' << '|' << setfill(' ') << endl;
	cout << '|' << setw(maxBookLength) << "Book Name" << '|' << setw(MAX_PRICE_LENGTH) << "Price ($)" << '|' << setw(MAX_ISBN_LENGTH) << "ISBN" << '|' << setw(MAX_QUANTITY_LENGTH) << "Stock" << '|' << endl;
	cout << '|' << setfill('-') << setw(maxBookLength) << '-' << '|' << setw(MAX_PRICE_LENGTH) << '-' << '|' << setw(MAX_ISBN_LENGTH) << '-' << '|' << setw(MAX_QUANTITY_LENGTH) << '-' << '|' << setfill(' ') << endl;

	for (list<book>::iterator it = this->bookList.begin(); it != this->bookList.end(); it++) {
		if (it->title.find(bookName) != string::npos) {
			cout << '|' << setw(maxBookLength) << it->title << '|' << setw(MAX_PRICE_LENGTH) << it->price << '|' << setw(MAX_ISBN_LENGTH) << it->ISBN << '|' << setw(MAX_QUANTITY_LENGTH) << it->stock << '|' << endl;

		}
	}

	cout << '|' << setfill('-') << setw(maxBookLength) << '-' << '|' << setw(MAX_PRICE_LENGTH) << '-' << '|' << setw(MAX_ISBN_LENGTH) << '-' << '|' << setw(MAX_QUANTITY_LENGTH) << '-' << '|' << setfill(' ') << endl;
}

void books::print() {
	using namespace std;
	cout << fixed << left << setprecision(2);
	cout << '|' << setfill('-') << setw(maxBookLength) << '-' << '|' << setw(MAX_PRICE_LENGTH) << '-' << '|' << setw(MAX_ISBN_LENGTH) << '-' << '|' << setw(MAX_QUANTITY_LENGTH) << '-' << '|' << setfill(' ') << endl;
	cout << '|' << setw(maxBookLength) << "Book Name" << '|' << setw(MAX_PRICE_LENGTH) << "Price ($)" << '|' << setw(MAX_ISBN_LENGTH) << "ISBN" << '|' << setw(MAX_QUANTITY_LENGTH) << "Stock" << '|' << endl;
	cout << '|' << setfill('-') << setw(maxBookLength) << '-' << '|' << setw(MAX_PRICE_LENGTH) << '-' << '|' << setw(MAX_ISBN_LENGTH) << '-' << '|' << setw(MAX_QUANTITY_LENGTH) << '-' << '|' << setfill(' ') << endl;

	for (std::list<book>::iterator it = this->bookList.begin(); it != this->bookList.end(); it++) {
		cout << '|' << setw(maxBookLength) << it->title << '|' << setw(MAX_PRICE_LENGTH) << it->price << '|' << setw(MAX_ISBN_LENGTH) << it->ISBN << '|' << setw(MAX_QUANTITY_LENGTH) << it->stock << '|' << endl;
	}

	cout << '|' << setfill('-') << setw(maxBookLength) << '-' << '|' << setw(MAX_PRICE_LENGTH) << '-' << '|' << setw(MAX_ISBN_LENGTH) << '-' << '|' << setw(MAX_QUANTITY_LENGTH) << '-' << '|' << setfill(' ') << endl;
}

bool books::delete_book(const std::string& bookName) {
	for (std::list<book>::iterator it = this->bookList.begin(); it != this->bookList.end(); it++) {
		if (it->title == bookName) {
			this->bookList.erase(it);
			return true;
		}
	}
	return false;
}