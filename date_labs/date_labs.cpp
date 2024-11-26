#include <iostream>
using namespace std;

// Структура для хранения даты
struct TDate {
    int Day;
    int Month;
    int Year;
};

// Функция для определения, является ли год високосным
bool LeapYear(TDate D) {
    if ((D.Year % 4 == 0 && D.Year % 100 != 0) || (D.Year % 400 == 0)) {
        return true;
    }
    return false;
}

// Функция для определения количества дней в месяце
int DaysInMonth(TDate D) {
    switch (D.Month) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2: {
        if (LeapYear(D)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    default:
        return 31;
    }
}


// Функция для проверки корректности даты
int CheckDate(TDate D) {
    if (D.Month < 1 || D.Month > 12) {
        return 1; // Неверный номер месяца
    }
    if (D.Day < 1 || D.Day > DaysInMonth(D)) {
        return 2; // Неверный день
    }
    return 0; // Дата корректна
}


// Функция для вывода информации о дате
void PrintDateInfo(TDate D) {
    cout << "Дата: " << D.Day << "/" << D.Month << "/" << D.Year << endl;

    // Проверяем високосность года
    cout << "  Год является високосным: " << (LeapYear(D) ? "Да" : "Нет") << endl;

    // Определяем количество дней в месяце
    if (CheckDate(D) == 0) {
        cout << "  Количество дней в месяце: " << DaysInMonth(D) << endl;
    }
    else {
        cout << "  Невозможно определить количество дней: дата некорректна." << endl;
    }

    // Проверяем корректность даты
    int result = CheckDate(D);
    if (result == 0) {
        cout << "  Дата корректна." << endl;
    }
    else if (result == 1) {
        cout << "  Ошибка: неверный номер месяца." << endl;
    }
    else {
        cout << "  Ошибка: неверный день." << endl;
    }

    cout << endl; // Разделитель между выводами для разных дат
}

// Основная программа
int main() {
    setlocale(LC_ALL, "russian");

    // Примеры дат
    TDate dates[5] = {
        {1, 1, 2000},   // Корректная дата
        {30, 2, 2023},  // Неверный день
        {29, 2, 2020},  // Корректная дата
        {15, 13, 2024}, // Неверный месяц
        {31, 12, 2024}  // Корректная дата
    };

    // Вывод информации для каждой даты
    for (int i = 0; i < 5; i++) {
        PrintDateInfo(dates[i]);
    }

    return 0;
}
