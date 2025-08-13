#include <iostream>
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
    void setBookDetails(string t, string a, string i, bool av, string d) {
        title = t;
        author = a;
        isbn = i;
        available = av;
        dateAdded = d;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "------------------------" << endl;
    }

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

    void returnBook() {
        available = true;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return available;
    }
};

int main() {
    Book books[8];

    books[0].setBookDetails("The Fellowship of the Ring", "J.R.R. Tolkien", "101", true, "2020-01-01");
    books[1].setBookDetails("The Lightning Thief", "Rick Riordan", "102", true, "2021-03-01");
    books[2].setBookDetails(" ", "Christopher Paolini", "103", true, " ");
    books[3].setBookDetails("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "104", true, "2021-09-15");
    books[4].setBookDetails("The Lion, the Witch and the Wardrobe", "C.S. Lewis", "105", true, "2022-11-12");
    books[5].setBookDetails("The Name of the Wind", "Patrick Rothfuss", "106", true, "2023-02-05");
    books[6].setBookDetails("NULL", " ", "107", false, "N/A");
    books[7].setBookDetails("The Neverending Story", "", "ISBN", true, "abc");

    cout << "Incorrect Books:\n\n";
    books[2].displayBookDetails();
    books[6].displayBookDetails();
    books[7].displayBookDetails();

    string inputISBN;
    while (true) {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting the program." << endl;
            break;
        }

        bool found = false;
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
