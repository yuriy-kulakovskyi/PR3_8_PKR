#include <fstream>
#include <iostream>
#include <string>
#include "./functions/functions.h"

using namespace std;

int main() {
    Book* library = nullptr;
    string filename = "../cmake-build-debug/books.txt";

    readBooksFromFile(filename, library);
    // виведення книг з файлу
    cout << "Книги з файлу:" << endl;
    printBooks(library);

    int choice;
    do {
        menu();
        cin >> choice;
        cin.ignore(); // очищення після введення числа

        switch (choice) {
        case 1:
            addBookFromInput(library);
            break;
        case 2: {
            string title;
            cout << "Введіть назву книги для видалення: ";
            getline(cin, title);
            removeBook(library, title);
            break;
        }
        case 3: {
            string title;
            cout << "Введіть назву книги для пошуку: ";
            getline(cin, title);
            Book* found = findBookByTitle(library, title);
            if (found) {
                cout << "Знайдено книгу: " << found->title
                    << ", Автор: " << found->author
                    << ", Рік: " << found->year << endl;
            }
            else {
                cout << "Книгу не знайдено." << endl;
            }
            break;
        }
        case 4:
            cout << "Каталог книг:" << endl;
            printBooks(library);
            break;
        case 0:
            cout << "Вихід..." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    clearBooks(library);
    return 0;
}
