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

    cout << "������ ���������:" << endl;
    for (size_t i = 0; i < studentsList.getSize(); ++i) {
        Student student = studentsList.get(i);
        cout << "�������: " << student.lastName << ", ���: " << student.firstName << ", ������: " << student.group << ", �������: " << student.studentID << endl;
    }

    char choice;
    do {
        cout << "\n�������� ��������:" << endl;
        cout << "1. �������� ��������" << endl;
        cout << "2. ������� ��������" << endl;
        cout << "3. ����� ��������" << endl;
        cout << "4. �������� ��������� �� ������" << endl;
        cout << "0. �����" << endl;
        cout << "������� ����� ��������: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string lastName, firstName, group;
            int studentID;
            cout << "������� �������: ";
            cin >> lastName;
            cout << "������� ���: ";
            cin >> firstName;
            cout << "������� ������: ";
            cin >> group;
            cout << "������� ����� �������: ";
            cin >> studentID;

            try {
                studentsList.add({ lastName, firstName, group, studentID });
                cout << "������� ��������." << endl;
            }
            catch (const exception& e) {
                cerr << "������: " << e.what() << endl;
            }
            break;
        }
        case '2': {
            int studentID;
            cout << "������� ����� �������� ������ �������� ��� ��������: ";
            cin >> studentID;

            try {
                studentsList.remove(studentID);
                cout << "������� � ������� �������� ������ " << studentID << " ������." << endl;
            }
            catch (const exception& e) {
                cerr << "������: " << e.what() << endl;
            }
            break;
        }
        case '3': {
            string lastName, firstName;
            cout << "������� ������� ��������: ";
            cin >> lastName;
            cout << "������� ��� ��������: ";
            cin >> firstName;

            vector<int> positions = studentsList.find(lastName, firstName);
            if (!positions.empty()) {
                cout << "�������� � �������� " << lastName << " � ������ " << firstName << " ������� �� ��������:";
                for (int pos : positions) {
                    cout << " " << pos;
                }
                cout << endl;
            }
            else {
                cout << "�������� � �������� " << lastName << " � ������ " << firstName << " �� �������." << endl;
            }
            break;
        }
        case '4': {
            string group;
            cout << "������� �������� ������: ";
            cin >> group;

            vector<string> groupStudents = studentsList.getStudentsByGroup(group);
            cout << "�������� ������ " << group << ":" << endl;
            for (const string& name : groupStudents) {
                cout << name << endl;
            }
            break;
        }
        case '0':
            cout << "�����." << endl;
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }

    } while (choice != '0');

    return 0;
}
