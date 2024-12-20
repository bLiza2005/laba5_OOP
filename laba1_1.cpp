#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Book {
private:
    std::string author;
    std::string title;
    std::string book_type;

public:
    // Конструктор с проверкой на пустые поля и правильный тип книги
    Book(std::string author, std::string title, std::string book_type) {
        if (author.empty() || title.empty()) {
            throw std::invalid_argument("У книги должны быть автор и название.");
        }
        if (book_type != "художественная" && book_type != "техническая") {
            throw std::invalid_argument("Тип книги должен быть 'художественная' или 'техническая'.");
        }
        this->author = author;
        this->title = title;
        this->book_type = book_type;
    }

    // Метод для вывода информации о книге
    void display() const {
        std::cout << "'" << title << "' от " << author << " (" << book_type << ")" << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    // Метод для добавления книги в библиотеку
    void add_book(const Book &book) {
        books.push_back(book);
    }

    // Метод для вывода всех книг в библиотеке
    void show_books() const {
        if (books.empty()) {
            std::cout << "Библиотека пуста." << std::endl;
        } else {
            for (const auto &book : books) {
                book.display();
            }
        }
    }
};

int main() {
    try {
        Library library;

        // Создание книг
        Book book1("Николас Спаркс", "Спеши Любить", "художественная");
        Book book2("Математика", "Математика", "техническая");
        Book book3("Иван Тургеньев", "Муму", "художественная");

        // Добавление книг в библиотеку
        library.add_book(book1);
        library.add_book(book2);
        library.add_book(book3);

        // Вывод книг
        library.show_books();
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

