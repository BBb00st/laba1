#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Структура з 10 характеристиками студента
struct Student {
    char lastName[50];       // 1. Прізвище
    char firstName[50];      // 2. Ім'я
    char patronymic[50];     // 3. По батькові
    int age;                 // 4. Вік
    int course;              // 5. Курс
    char groupName[20];      // 6. Назва групи
    char gradebookNumber[20];// 7. Номер заліковки
    double averageScore;     // 8. Середній бал
    char specialty[100];     // 9. Спеціальність
    bool isBudget;           // 10. Форма навчання (true - бюджет, false - контракт)
};

int main() {
    // Встановлюємо українську локалізацію для консолі
    setlocale(LC_ALL, "Ukrainian");

    // Створюємо об'єкт структури та заповнюємо його твоїми реальними даними
    Student stud;
    strcpy_s(stud.lastName, "Моісєенко");
    strcpy_s(stud.firstName, "Максим");
    strcpy_s(stud.patronymic, "Олександрович");
    stud.age = 19;
    stud.course = 2; // Автоматично вираховано для групи ІСТ-25-1 (вступ у 2025 році)
    strcpy_s(stud.groupName, "ІСТ-25-1");
    strcpy_s(stud.gradebookNumber, "ІСТ-777"); // Шаблон заліковки
    stud.averageScore = 3.0;
    strcpy_s(stud.specialty, "Інформаційні Системи Та Технології");
    stud.isBudget = false; // Контрактна форма навчання

    // СПОСІБ 1: Запис як текстова інформація
    ofstream textFile("student_text.txt");
    if (textFile.is (http://textFile.is/)_open()) {
        textFile << "--- ДАНІ СТУДЕНТА (ТЕКСТОВИЙ РЕЖИМ) ---\n";
        textFile << "Прізвище: " << stud.lastName << "\n";
        textFile << "Ім'я: " << stud.firstName << "\n";
        textFile << "По батькові: " << stud.patronymic << "\n";
        textFile << "Вік: " << stud.age << "\n";
        textFile << "Курс: " << stud.course << "\n";
        textFile << "Група: " << stud.groupName << "\n";
        textFile << "№ заліковки: " << stud.gradebookNumber << "\n";
        textFile << "Середній бал: " << stud.averageScore << "\n";
        textFile << "Спеціальність: " << stud.specialty << "\n";
        textFile << "Форма навчання: " << (stud.isBudget ? "Бюджет" : "Контракт") << "\n";

        textFile.close();
        cout << "Спосiб 1: Текстовий файл 'student_text.txt' успiшно оновлено.\n";
    }
    else {
        cout << "Помилка відкриття файлу для тексту.\n";
    }

    // СПОСІБ 2: Запис у вигляді двійкової структури
    ofstream binFile("student_struct.bin", ios::binary);
    if (binFile.is (http://binFile.is/)_open()) {
        binFile.write(reinterpret_cast<char*>(&stud), sizeof(Student));
        binFile.close();
        cout << "Спосiб 2: Бінарний файл 'student_struct.bin' успiшно оновлено.\n";
    }
    else {
        cout << "Помилка відкриття бінарного файлу.\n";
    }

    return 0;
}