#include <iostream>
#include <stdexcept>
#include <memory>

class Person {
public:
    virtual void info() const = 0; // Чистая виртуальная функция
    virtual ~Person() = default;    // Виртуальный деструктор
};

class Preschooler : public Person {
public:
    void info() const override {
        std::cout << "Я дошкольник." << std::endl;
    }
};

class Schoolboy : public Person {
public:
    void info() const override {
        std::cout << "Я школьник." << std::endl;
    }
};

class Student : public Person {
public:
    void info() const override {
        std::cout << "Я студент." << std::endl;
    }
};

class Working : public Person {
public:
    void info() const override {
        std::cout << "Я работающий." << std::endl;
    }
};

template <typename T>
class PointerArray {
private:
    T** arr;
    size_t size;

public:
    PointerArray(size_t size) : size(size) {
        if (size == 0) {
            throw std::overflow_error("Размер массива должен быть положительным.");
        }
        arr = new T*[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = nullptr; // Инициализация указателей
        }
    }

    ~PointerArray() {
        for (size_t i = 0; i < size; ++i) {
            delete arr[i]; // Освобождение памяти для объектов
        }
        delete[] arr; // Освобождение памяти для массива указателей
    }

    T*& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return arr[index]; // Возвращаем ссылку на указатель
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    try {
        const size_t arraySize = 5; // Размер массива
        PointerArray<Person> people(arraySize);

        // Создание объектов
        people[0] = new Preschooler();
        people[1] = new Schoolboy();
        people[2] = new Student();
        people[3] = new Working();

        // Демонстрация работы
        for (size_t i = 0; i < arraySize; ++i) {
            if (people[i]) { // Проверяем, существует ли объект
                people[i]->info();
            }
        }

        // Пример обработки исключения для недопустимого индекса
        try {
            people[5]; // Попытка обращения к несуществующему индексу
        } catch (const std::out_of_range& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }

    } catch (const std::overflow_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
