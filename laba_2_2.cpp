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

// Базовый класс Sales
class Sales {
protected:
    float sales[3]; // Массив для хранения продаж за 3 месяца

public:
    Sales() {
        for (int i = 0; i < 3; i++) {
            sales[i] = 0.0f;
        }
    }

    void inputSales() {
        cout << "Введите общую стоимость проданных книг за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void outputSales() {
        cout << "Продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << " р." << endl;
        }
    }
};

// Класс Book, наследуемый от Publication и Sales
class Book : public Publication, public Sales {
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
        inputSales(); // Получаем данные о продажах
    }

    void putdata() {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        outputSales(); // Выводим данные о продажах
    }
};

// Класс Audio, наследуемый от Publication и Sales
class Audio : public Publication, public Sales {
private:
    int duration;

public:
    Audio() : duration(0) {}

    void getdata() {
        cout << "Введите название аудиозаписи: ";
        cin >> title;
        cout << "Введите цену аудиозаписи: ";
        cin >> price;
        cout << "Введите время записи в минутах: ";
        cin >> duration;
        cin.ignore(); // Игнорируем символ новой строки после ввода числа
        inputSales(); // Получаем данные о продажах
    }

    void putdata() {
        Publication::putdata();
        cout << "Время записи: " << duration << " минут" << endl;
        outputSales(); // Выводим данные о продажах
    }
};

// Главная функция
int main() {
    system("chcp 1251");
    Book book;
    Audio audio;

    cout << "Пожалуйста, введите данные о книге:" <<
        endl;
    book.getdata();

    cout << "\nПожалуйста, введите данные о аудиозаписи:" << endl;
    audio.getdata();

    cout << "\nДанные о книге:" << endl;
    book.putdata();

    cout << "\nДанные о аудиозаписи:" << endl;
    audio.putdata();

    return 0;
}
