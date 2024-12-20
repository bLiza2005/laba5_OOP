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

    // Получение типа книги
    std::string get_book_type() const {
        return book_type;
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

    // Процедура для подсчета количества книг каждого типа с использованием switch
    void count_books() const {
        int fiction_count = 0;
        int technical_count = 0;

        for (const auto &book : books) {
            std::string type = book.get_book_type();

            // Используем switch для подсчета книг по типу
            switch (type == "художественная") {
                case true:
                    fiction_count++;
                    break;
                case false:
                    technical_count++;
                    break;
            }
        }

        std::cout << "Количество художественной литературы: " << fiction_count << std::endl;
        std::cout << "Количество технической литературы: " << technical_count << std::endl;
    }
};

int main() {
    try {
        Library library;

        // Создание книг
        Book book1(" Николас Спаркс", "Спекши любить", "художественная");
        Book book2("Математика", "Математикка", "техническая");
        Book book3("Иван Тургеньев", "Муму", "художественная");

        // Добавление книг в библиотеку
        library.add_book(book1);
        library.add_book(book2);
        library.add_book(book3);

        // Вывод всех книг
        library.show_books();

        // Подсчет количества книг по типу
        library.count_books();
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
