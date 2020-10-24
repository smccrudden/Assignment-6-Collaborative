/* Author:Seth McCrudden
* Last date modified: 24-Oct-2020
* File name: books.h
* Description: Definition of the books class
*/
#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "book.h"

#define MAX_PRICE_LENGTH 10
#define MAX_ISBN_LENGTH 13
#define MAX_QUANTITY_LENGTH 10

class books
{
private:
	std::list<book> bookList;
	unsigned int maxBookLength; // The maximum length of all the books in the list. Used for formatting output
	int compareBookNames(const std::string& first, const std::string& second);
	/* Description:
	 *    Compares two strings to find out which should come first or if they are equal
	 *
	 * Parameters:
	 *    first, second - Books to compare.
	 *
	 * Return:
	 *    returns 0 if characters compared of first and second are equal
	 *    returns -1 if first should come first (first < second)
	 *    returns 1 if second should come first (second < first)
	 *
	 */
public:
	books();
	/* Description:
	 *    Initializes an empty book inventory.
	 *
	 * Post-conditions:
	 *    maxBookLength=10.
	 */

	~books();
	/* Description:
	 *    Deallocates all the data in the linked list
	 *
	 * Post-conditions:
	 *    linked list has been cleared, maxBookLength=10.
	 */

	void insert_sorted(const book& bookToAdd);
	/* Description:
	 *    Inserts the book at the appropriate position so that the previous book is
	 *    lexicographically smaller and the next book is lexicographically greater
	 *    than the inserted book
	 *
	 * Parameters:
	 *    bookToAdd - The book to be inserted.
	 *
	 * Postconditions:
	 *    bookToAdd is inserted at the appropriate position
	 *
	 */

	bool read_from_file(const std::string& fileName);
	/* Description:
	 *    Creates a new books list from the data in the file
	 *
	 * Parameters:
	 *    fileName - The file to read the data from.
	 *
	 * Return:
	 *    returns false if the file couldn't be open and true if everything was successful
	 *
	 */

	bool write_to_file(const std::string& fileName);
	/* Description:
	 *    Writes the books list stored to a file
	 *
	 * Parameters:
	 *    fileName - The file to write the data to.
	 *
	 * Return:
	 *    returns false if the file couldn't be open and true if everything was successful
	 *
	 */

	void lookup(const std::string& bookName);
	/* Description:
	 *    Prints all book which contains bookName.
	 */

	void print();
	/* Description:
	 *    Loops through the linked list and outputs all the data
	 */

	bool delete_book(const std::string& bookName);
	/* Description:
	 *    Deletes the book in the linked list that has that book name.
	 *
	 * Parameters:
	 *    bookName - The book to be deleted.
	 *
	 * Postconditions:
	 *    Searches the list for bookName and deletes it from the linked list
	 *
	 * Return:
	 *    returns true if the book was deleted and false if it wasn't found
	 */
};

