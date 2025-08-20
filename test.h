#ifndef TEST_H
#define TEST_H

#include "book.h"
#include <iostream>
using namespace std;

// Function declarations for testing
void testCorrectBooks();
void testIncorrectBooks();
void testSortingAscending();
void testSortingDescending();
void testSortingMixed();
void sortBooksByTitle(Book books[], int size);
void runAllTests();

#endif
