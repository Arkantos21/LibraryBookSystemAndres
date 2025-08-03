#include <iostream>
#include <string>
using namespace std;

// [Commit 1] Book class: stores title, author, ISBN, availability, and added date
class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    // Sets all book details
    void setBookDetails(string t, string a, string i, bool av, string d) {
        title = t;
        author = a;
        isbn = i;
        available = av;
        dateAdded = d;
    }

    // Displays book information
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "------------------------" << endl;
    }

    // Borrows the book if available
    bool borrowBook() {
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

    // Returns the book (makes it available again)
    void returnBook() {
        available = true;
    }

    // Returns the ISBN of the book
    string getISBN() {
        return isbn;
    }

    // Checks if the book is available
    bool isAvailable() {
        return available;
    }
};

int main() {
    Book books[8]; // Book list

    // Sets up the list of books in the system
    books[0].setBookDetails("The Fellowship of the Ring", "J.R.R. Tolkien", "101", true, "2020-01-01");
    books[1].setBookDetails("Percy Jackson: The Lightning Thief", "Rick Riordan", "102", true, "2021-03-01");
    books[2].setBookDetails("Eragon", "Christopher Paolini", "103", true, "2022-05-20");
    books[3].setBookDetails("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "104", true, "2021-09-15");
    books[4].setBookDetails("The Lion, the Witch and the Wardrobe", "C.S. Lewis", "105", true, "2022-11-12");
    books[5].setBookDetails("The Name of the Wind", "Patrick Rothfuss", "106", true, "2023-02-05");
    books[6].setBookDetails("The Iliad", "Homer", "107", false, "2019-08-30"); // Already borrowed
    books[7].setBookDetails("The Neverending Story", "Michael Ende", "108", true, "2020-12-20");

    string inputISBN;

    // Loop to allow borrowing books by ISBN
    while (true) {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting the program." << endl;
            break;
        }

        bool found = false;

        // Search for the book by ISBN
        for (int i = 0; i < 8; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                }
                else {
                    cout << "Error: Book is not available." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found." << endl;
        }
    }

    return 0;
}
