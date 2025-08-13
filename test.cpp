#include <iostream>
#include "book.h"
using namespace std;

int main() {
    Book testBook;
    testBook.setBookDetails("Test Book", "Test Author", "999", true, "2025-01-01");

    cout << "Testing displayBookDetails():" << endl;
    testBook.displayBookDetails();

    cout << "Testing borrowBook():" << endl;
    testBook.borrowBook();

    cout << "Testing isAvailable() after borrowing:" << endl;
    cout << (testBook.isAvailable() ? "Available" : "Not Available") << endl;

    cout << "Testing returnBook():" << endl;
    testBook.returnBook();

    cout << "Testing isAvailable() after returning:" << endl;
    cout << (testBook.isAvailable() ? "Available" : "Not Available") << endl;

    return 0;
}
