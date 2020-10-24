/* Author:Seth McCrudden
* Last date modified: 24-Oct-2020
* File name: main.cpp
* Description: Provides an interface for the user to interact with the book inventory.
*/

#include "books.h"

int main() {
	using namespace std;
	int choice = 0;
	books inv;
	while (choice != 6) {
		cout << "Welcome to the BookStore Inventory! You may select one of the following options:\n" <<
			"1 Build an inventory from a file\n" <<
			"2 Write the inventory to a file\n" <<
			"3 Print the inventory\n" <<
			"4 Search for the stock by the substring of a title\n" <<
			"5 Delete a book from the inventory\n" <<
			"6 Exit this program\n" <<
			"\n" <<
			"Please enter your choice now: ";
		string input;
		getline(cin, input);
		choice = stoi(input);
		switch (choice) {
			case 1: {
				string fileName;
				cout << "File Name: ";
				getline(cin, fileName);
				cout << "\n";
				if (inv.read_from_file(fileName)) {
					cout << "Read from file successfully" << endl;
				}
				else {
					cout << "Failed to open file!" << endl;
				}
				cout << "\n";
				break;
			}
			case 2: {
				string fileName;
				cout << "File Name: ";
				getline(cin, fileName);
				cout << "\n";
				if (inv.write_to_file(fileName)) {
					cout << "Written to file successfully" << endl;
				}
				else {
					cout << "Failed to open file!" << endl;
				}
				cout << "\n";
				break;
			}
			case 3: {
				cout << "\n";
				inv.print();
				cout << "\n";
				break;
			}
			case 4: {
				string bookName;
				cout << "Book Substring: ";
				getline(cin, bookName);
				cout << "\n";
				inv.lookup(bookName);
				cout << "\n";
				break;
			}
			case 5: {
				string bookName;
				cout << "Book Name: ";
				getline(cin, bookName);
				cout << "\n";
				if (inv.delete_book(bookName)) {
					cout << "Book deleted successfully" << endl;
				}
				else {
					cout << "Book not found" << endl;
				}
				cout << "\n";
				break;
			}
		}
	}
}