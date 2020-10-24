/* Author:Seth McCrudden
* Last date modified: 24-Oct-2020
* File name: book.h
* Description: Definitions for the book struct
*/
#pragma once
#include <string>

struct book {
	std::string title;
	double price = 0;
	std::string ISBN; // 13 character ISBN
	int stock = 0;
};