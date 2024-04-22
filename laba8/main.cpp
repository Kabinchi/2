#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList studentsList;

    studentsList.add({ "Ivanov", "Ivan", "TMsp-100", 1234 });
    studentsList.add({ "Petrov", "Egor", "TRsp-322", 4321 });
    studentsList.add({ "Sidorov", "Sidor", "TMsp-100", 9876 });
    studentsList.add({ "Ivanov", "Petr", "PKsp-121", 2468 });

    cout << "Список студентов:" << endl;
    for (size_t i = 0; i < studentsList.getSize(); ++i) {
        Student student = studentsList.get(i);
        cout << "Фамилия: " << student.lastName << ", Имя: " << student.firstName << ", Группа: " << student.group << ", Зачетка: " << student.studentID << endl;
    }

    char choice;
    do {
        cout << "\nВыберите действие:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Найти студента" << endl;
        cout << "4. Получить студентов по группе" << endl;
        cout << "0. Выйти" << endl;
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string lastName, firstName, group;
            int studentID;
            cout << "Введите фамилию: ";
            cin >> lastName;
            cout << "Введите имя: ";
            cin >> firstName;
            cout << "Введите группу: ";
            cin >> group;
            cout << "Введите номер зачетки: ";
            cin >> studentID;

            try {
                studentsList.add({ lastName, firstName, group, studentID });
                cout << "Студент добавлен." << endl;
            }
            catch (const exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case '2': {
            int studentID;
            cout << "Введите номер зачетной книжки студента для удаления: ";
            cin >> studentID;

            try {
                studentsList.remove(studentID);
                cout << "Студент с номером зачетной книжки " << studentID << " удален." << endl;
            }
            catch (const exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case '3': {
            string lastName, firstName;
            cout << "Введите фамилию студента: ";
            cin >> lastName;
            cout << "Введите имя студента: ";
            cin >> firstName;

            vector<int> positions = studentsList.find(lastName, firstName);
            if (!positions.empty()) {
                cout << "Студенты с фамилией " << lastName << " и именем " << firstName << " найдены на позициях:";
                for (int pos : positions) {
                    cout << " " << pos;
                }
                cout << endl;
            }
            else {
                cout << "Студенты с фамилией " << lastName << " и именем " << firstName << " не найдены." << endl;
            }
            break;
        }
        case '4': {
            string group;
            cout << "Введите название группы: ";
            cin >> group;

            vector<string> groupStudents = studentsList.getStudentsByGroup(group);
            cout << "Студенты группы " << group << ":" << endl;
            for (const string& name : groupStudents) {
                cout << name << endl;
            }
            break;
        }
        case '0':
            cout << "Выход." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }

    } while (choice != '0');

    return 0;
}
