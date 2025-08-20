#include "test.h"
#include "book.h"

void sortBooksByTitle(Book books[], int size) {
    // Tu código actual de bubble sort está bien, manténlo
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getTitle() > books[j + 1].getTitle()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void testCorrectBooks() {
    cout << "\n=== TESTING CORRECT BOOKS ===" << endl;
    Book correctBooks[3];

    // Exactly as specified in Assessment 3
    correctBooks[0].setBookDetails("The Fellowship of the Ring", "J.R.R. Tolkien", "101", true, "2020-01-01");
    correctBooks[1].setBookDetails("The Lightning Thief", "Rick Riordan", "102", true, "2021-03-01");
    correctBooks[2].setBookDetails("The Name of the Wind", "Patrick Rothfuss", "106", true, "2023-02-05");

    cout << "BEFORE SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        correctBooks[i].displayBookDetails();
    }

    sortBooksByTitle(correctBooks, 3);

    cout << "\nAFTER SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        correctBooks[i].displayBookDetails();
    }
}

void testIncorrectBooks() {
    cout << "\n=== TESTING INCORRECT BOOKS ===" << endl;
    Book incorrectBooks[3];

    // Exactly as specified in Assessment 3
    incorrectBooks[0].setBookDetails("-", "Christopher Paolini", "103", true, "-");
    incorrectBooks[1].setBookDetails("NULL", "-", "107", false, "N/A");
    incorrectBooks[2].setBookDetails("The Neverending Story", "", "ISBN", true, "abc");

    cout << "BEFORE SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        incorrectBooks[i].displayBookDetails();
    }

    sortBooksByTitle(incorrectBooks, 3);

    cout << "\nAFTER SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        incorrectBooks[i].displayBookDetails();
    }
}

void testSortingAscending() {
    cout << "\n=== TEST ARRAY 1: ASCENDING ORDER ===" << endl;
    Book ascendingBooks[3];

    // Already in ascending order
    ascendingBooks[0].setBookDetails("A Book", "Author A", "001", true, "2020-01-01");
    ascendingBooks[1].setBookDetails("B Book", "Author B", "002", true, "2021-01-01");
    ascendingBooks[2].setBookDetails("C Book", "Author C", "003", true, "2022-01-01");

    cout << "BEFORE SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Title: " << ascendingBooks[i].getTitle() << endl;
    }

    sortBooksByTitle(ascendingBooks, 3);

    cout << "\nAFTER SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Title: " << ascendingBooks[i].getTitle() << endl;
    }
}

void testSortingDescending() {
    cout << "\n=== TEST ARRAY 2: DESCENDING ORDER ===" << endl;
    Book descendingBooks[3];

    // In descending order
    descendingBooks[0].setBookDetails("Z Book", "Author Z", "026", true, "2020-01-01");
    descendingBooks[1].setBookDetails("M Book", "Author M", "013", true, "2021-01-01");
    descendingBooks[2].setBookDetails("A Book", "Author A", "001", true, "2022-01-01");

    cout << "BEFORE SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Title: " << descendingBooks[i].getTitle() << endl;
    }

    sortBooksByTitle(descendingBooks, 3);

    cout << "\nAFTER SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Title: " << descendingBooks[i].getTitle() << endl;
    }
}

void testSortingMixed() {
    cout << "\n=== TEST ARRAY 3: MIXED ORDER ===" << endl;
    Book mixedBooks[3];

    // Mixed order
    mixedBooks[0].setBookDetails("M Book", "Author M", "013", true, "2020-01-01");
    mixedBooks[1].setBookDetails("A Book", "Author A", "001", true, "2021-01-01");
    mixedBooks[2].setBookDetails("Z Book", "Author Z", "026", true, "2022-01-01");

    cout << "BEFORE SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Title: " << mixedBooks[i].getTitle() << endl;
    }

    sortBooksByTitle(mixedBooks, 3);

    cout << "\nAFTER SORTING:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Title: " << mixedBooks[i].getTitle() << endl;
    }
}

void runAllTests() {
    cout << "===========================================" << endl;
    cout << "        BOOK TESTING SUITE" << endl;
    cout << "===========================================" << endl;

    testCorrectBooks();
    testIncorrectBooks();
    testSortingAscending();
    testSortingDescending();
    testSortingMixed();

    cout << "\n=== ALL TESTS COMPLETED SUCCESSFULLY ===" << endl;
}

int main() {
    runAllTests();
    return 0;
}
