#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "student.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

struct Node {
    Student data;
    Node* next;
    Node* prev;

    Node(const Student& student) : data(student), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void add(const Student& student) {
        if (contains(student)) {
            throw std::runtime_error("Студент уже существует в списке.");
        }

        Node* newNode = new Node(student);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void remove(int studentID) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.studentID == studentID) {
                if (current == head) {
                    head = current->next;
                }
                if (current == tail) {
                    tail = current->prev;
                }
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                size--;
                return;
            }
            current = current->next;
        }
        throw std::runtime_error("Студент с указанным номером зачётной книжки не найден.");
    }

    Student get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка.");
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    std::vector<int> find(const std::string& lastName, const std::string& firstName) {
        std::vector<int> positions;
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data.lastName == lastName && current->data.firstName == firstName) {
                positions.push_back(index);
            }
            current = current->next;
            index++;
        }
        return positions;
    }

    std::vector<std::string> getStudentsByGroup(const std::string& group) {
        std::vector<std::string> names;
        Node* current = head;
        while (current != nullptr) {
            if (current->data.group == group) {
                names.push_back(current->data.lastName + " " + current->data.firstName);
            }
            current = current->next;
        }
        return names;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    bool contains(const Student& student) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.lastName == student.lastName &&
                current->data.firstName == student.firstName &&
                current->data.group == student.group &&
                current->data.studentID == student.studentID) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    size_t getSize() const {
        return size;
    }
};

#endif
