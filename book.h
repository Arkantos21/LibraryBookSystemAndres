#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    void setBookDetails(string t, string a, string i, bool av, string d);
    void displayBookDetails();
    bool borrowBook();
    void returnBook();
    string getISBN();
    bool isAvailable();
    string getTitle();
};

#endif
