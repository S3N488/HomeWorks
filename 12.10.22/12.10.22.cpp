#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

Book books[10];

int main() {
    int choice;

    // Initialize the array of books
    books[0] = { "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Pan Books", "Science fiction" };
    books[1] = { "1984", "George Orwell", "Secker & Warburg", "Dystopian fiction" };
    books[2] = { "To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.", "Southern Gothic" };
    books[3] = { "The Catcher in the Rye", "J. D. Salinger", "Little, Brown and Company", "Bildungsroman" };
    books[4] = { "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Tragedy" };
    books[5] = { "Animal Farm", "George Orwell", "Secker & Warburg", "Political satire" };
    books[6] = { "Brave New World", "Aldous Huxley", "Chatto & Windus", "Dystopian fiction" };
    books[7] = { "The Lord of the Rings", "J. R. R. Tolkien", "Allen & Unwin", "High fantasy" };
    books[8] = { "Pride and Prejudice", "Jane Austen", "T. Egerton, Whitehall", "Romance novel" };
    books[9] = { "Frankenstein", "Mary Shelley", "Lackington, Hughes, Harding, Mavor, & Jones", "Gothic horror" };

    do {
        // Display the menu
        cout << "\n\nLibrary Program\n\n";
        cout << "1. Edit a book\n";
        cout << "2. Print all books\n";
        cout << "3. Search for books by author\n";
        cout << "4. Search for books by title\n";
        cout << "5. Sort array by book title\n";
        cout << "6. Sort array by author\n";
        cout << "7. Sort array by publisher\n";
        cout << "8. Exit\n\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
        case 1: // Edit a book
        {
            int index;
            cout << "Enter the index of the book you want to edit (0-9): ";
            cin >> index;

            if (index < 0 || index >= 10) {
                cout << "Invalid index\n";
            }
            else {
                cout << "Enter the new title: ";
                cin.ignore();
                getline(cin, books[index].title);
                cout << "Enter the new author: ";
                getline(cin, books[index].author);
                cout << "Enter the new publisher: ";
                getline(cin, books[index].publisher);
                cout << "Enter the new genre: ";
                getline(cin, books[index].genre);
                cout << "Book updated successfully\n";
            }
        }
        break;

        case 2: // Print all books
        {
            cout << "\nList of books:\n\n";
            for (int i = 0; i < 10; i++) {
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Publisher: " << books[i].publisher << endl;
                cout << "Genre: " << books[i].genre << endl << endl;
            }
        }
        break;

        case 3: // Search for books by author
        {
            string author;
            bool found = false;

            cout << "Enter the author name: ";
            cin.ignore();
            getline(cin, author);

            cout << "\nList of books by " << author << ":\n\n";
            for (int i = 0; i < 10; i++) {
                if (books[i].author == author) {
                    cout << "Title: " << books[i].title << endl;
                    cout << "Publisher: " << books[i].publisher << endl;
                    cout << "Genre: " << books[i].genre << endl << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "No books found by " << author << endl;
            }
        }
        break;

        case 4: // Book search by title
        {
            string title;
            bool found = false;

            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, title);

            for (int i = 0; i < 10; i++) {
                if (books[i].title == title) {
                    cout << "\nBook details:\n\n";
                    cout << "Title: " << books[i].title << endl;
                    cout << "Author: " << books[i].author << endl;
                    cout << "Publisher: " << books[i].publisher << endl;
                    cout << "Genre: " << books[i].genre << endl << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No book found with title: " << title << endl;
            }
        }
        break;

        case 5: // Sort array by book title
        {
            sort(books, books + 10, [](Book a, Book b) {
                return a.title < b.title;
                });

            cout << "\nBooks sorted by title:\n\n";
            for (int i = 0; i < 10; i++) {
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Publisher: " << books[i].publisher << endl;
                cout << "Genre: " << books[i].genre << endl << endl;
            }
        }
        break;

        case 6: // Sort array by author
        {
            sort(books, books + 10, [](Book a, Book b) {
                return a.author < b.author;
                });

            cout << "\nBooks sorted by author:\n\n";
            for (int i = 0; i < 10; i++) {
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Publisher: " << books[i].publisher << endl;
                cout << "Genre: " << books[i].genre << endl << endl;
            }
        }
        break;

        case 7: // Sort array by publisher
        {
            sort(books, books + 10, [](Book a, Book b) {
                return a.publisher < b.publisher;
                });

            cout << "\nBooks sorted by publisher:\n\n";
            for (int i = 0; i < 10; i++) {
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Publisher: " << books[i].publisher << endl;
                cout << "Genre: " << books[i].genre << endl << endl;
            }
        }
        break;

        case 8: // Exit program
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number from 1 to 8.\n";
            break;
        }

        // Wait for user to press Enter before continuing
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();

        // Clear console screen
        system("clear");

    } while (choice != 8);

}

