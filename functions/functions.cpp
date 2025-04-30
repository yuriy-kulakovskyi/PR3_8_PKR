#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

// Додавання книги в кінець списку
void addBook(Book*& head, const string& title, const string& author, int year) {
    Book* newBook = new Book{ title, author, year, nullptr, nullptr };
    if (!head) {
        head = newBook;
    }
    else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
        newBook->prev = temp;
    }
}

// Додавання книги вручну
void addBookFromInput(Book*& head) {
    string title, author;
    int year;

    cout << "Введіть назву книги: ";
    getline(cin, title);

    cout << "Введіть автора книги: ";
    getline(cin, author);

    cout << "Введіть рік видання: ";
    cin >> year;
    cin.ignore(); // Очищення буфера після cin

    addBook(head, title, author, year);
}

// Виведення всього списку
void printBooks(const Book* head) {
    if (!head) {
        cout << "Каталог порожній." << endl;
        return;
    }
    const Book* temp = head;
    while (temp) {
        cout << "Назва: " << temp->title
            << ", Автор: " << temp->author
            << ", Рік: " << temp->year << endl;
        temp = temp->next;
    }
}

// Пошук книги за назвою
Book* findBookByTitle(const Book* head, const string& title) {
    const Book* temp = head;
    while (temp) {
        if (temp->title == title) {
            return const_cast<Book*>(temp); // повертаємо неконстантний покажчик
        }
        temp = temp->next;
    }
    return nullptr;
}

// Видалення книги за назвою
void removeBook(Book*& head, const string& title) {
    Book* temp = head;
    while (temp) {
        if (temp->title == title) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            else {
                head = temp->next; // видаляємо голову
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Книгу \"" << title << "\" видалено з каталогу." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Книгу \"" << title << "\" не знайдено." << endl;
}

// Зчитування книг із файлу
void readBooksFromFile(const string& filename, Book*& head) {
    ifstream file(filename);
    if (file.is_open()) {
        string title, author;
        int year;
        while (getline(file, title) && getline(file, author) && (file >> year)) {
            file.ignore(); // Пропустити символ переведення рядка після числа
            addBook(head, title, author, year);
        }
        file.close();
    }
    else {
        cerr << "Не вдалося відкрити файл " << filename << endl;
    }
}

// Очищення всього списку
void clearBooks(Book*& head) {
    Book* temp = head;
    while (temp) {
        Book* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

// Меню
void menu() {
    cout << "\nМеню:\n";
    cout << "1. Додати книгу\n";
    cout << "2. Видалити книгу\n";
    cout << "3. Знайти книгу\n";
    cout << "4. Вивести каталог\n";
    cout << "0. Вийти\n";
    cout << "Ваш вибір: ";
}
