#include "book.h"
#include <iostream>
using namespace std;

void Book::setBookDetails(string t, string a, string i, bool av, string d) {
    title = t;
    author = a;
    isbn = i;
    available = av;
    dateAdded = d;
}

void Book::displayBookDetails() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Available: " << (available ? "Yes" : "No") << endl;
    cout << "Date Added: " << dateAdded << endl;
    cout << "------------------------" << endl;
}

bool Book::borrowBook() {
    if (available) {
        available = false;
        cout << "Book borrowed successfully.\n";
        return true;
    }
    else {
        cout << "Book is not available.\n";
        return false;
    }
}

void Book::returnBook() {
    available = true;
}

string Book::getISBN() {
    return isbn;
}

bool Book::isAvailable() {
    return available;
}

string Book::getTitle() {
    return title;
}
