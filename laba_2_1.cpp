#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}

    void putdata() {
        cout << "Название: " << title << ", Цена: " << price << " р." << endl;
    }
};

// Класс Book, наследуемый от Publication
class Book : public Publication {
private:
    int pages;

public:
    Book() : pages(0) {}

    void getdata() {
        cout << "Введите название книги: ";
        getline(cin, title);
        cout << "Введите цену книги: ";
        cin >> price;
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(); // Игнорируем символ новой строки после ввода числа
    }

    void putdata() {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
};

// Класс Audio, наследуемый от Publication
class Audio : public Publication {
private:
    int duration;

public:
    Audio() : duration(0) {}

    void getdata() {
        cout << "Введите название аудиозаписи: ";
        cin.clear();
        getline(cin, title);
        cout << "Введите цену аудиозаписи: ";
        cin >> price;
        cout << "Введите время записи в минутах: ";
        cin >> duration;
        cin.ignore(); // Игнорируем символ новой строки после ввода числа
    }

    void putdata() {
        Publication::putdata();
        cout << "Время записи: " << duration << " минут" << endl;
    }
};

// Главная функция
int main() {
    system("chcp 1251");
    Book book;
    Audio audio;

    cout << "Пожалуйста, введите данные о книге:" << endl;
    book.getdata();
    cout << "\nПожалуйста, введите данные о аудиозаписи:" << endl;
    audio.getdata();

    cout << "\nДанные о книге:" << endl;
    book.putdata();

    cout << "\nДанные о аудиозаписи:" << endl;
    audio.putdata();

    return 0;
}
