#include <iostream>
#include <string>
using namespace std;

class Book {
	
private:
    string title;
    string author;
    
public:
    Book(string t, string a) {
        title = t;
        author = a;
    }
    string getTitle() { return title; }
    void show() { cout << title << " by " << author << endl; }
};

class Member {
	
private:
    string name;
    Book* borrowedBook;
public:
	
    Member(string n) {
        name = n;
        borrowedBook = nullptr;
    }
    void borrowBook(Book* b) {
        if (borrowedBook != nullptr) {
            cout << name << " already has a book. Return it first." << endl;
        } else {
            borrowedBook = b;
            cout << name << " borrowed " << borrowedBook->getTitle() << endl;
        }
    }
    void returnBook() {
        if (borrowedBook == nullptr) {
            cout << name << " has nothing to return." << endl;
        } else {
            cout << name << " returned " << borrowedBook->getTitle() << endl;
            borrowedBook = nullptr;
        }
    }
    void showStatus() {
        if (borrowedBook != nullptr) {
            cout << name << " is reading " << borrowedBook->getTitle() << endl;
        } else {
            cout << name << " has no book." << endl;
        }
    }
};

int main() {
    Book book1("1984", "George Orwell");
    Book book2("To Kill a Mockingbird", "Harper Lee");
    
    Member ayesha("Ayesha");
    
    ayesha.showStatus();
    ayesha.borrowBook(&book1);
    ayesha.borrowBook(&book2);
    ayesha.returnBook();
    ayesha.borrowBook(&book2);
    ayesha.showStatus();
    
    {
        Member hassan("Hassan");
        hassan.borrowBook(&book1);
        hassan.showStatus();
    }
    book1.show();
    return 0;
}