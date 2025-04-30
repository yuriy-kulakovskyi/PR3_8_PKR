#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

struct Book {
  string title;
  string author;
  int year;
  Book* next;
  Book* prev;
};

void addBook(Book*& head, const string& title, const string& author, int year);
void addBookFromInput(Book*& head);
void printBooks(const Book* head);
Book* findBookByTitle(const Book* head, const string& title);
void removeBook(Book*& head, const string& title);
void readBooksFromFile(const string& filename, Book*& head);
void clearBooks(Book*& head);
void menu();


#endif //FUNCTIONS_H