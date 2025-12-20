#include "StudentVector.hpp"

StudentVector::StudentVector() {
    capacity = 10;
    len = 0;
    p = new Student*[capacity];
}

StudentVector::~StudentVector() {
    delete[] p; // Only deletes the array of pointers, not the students
}

void StudentVector::Clear() {
    len = 0;
}

void StudentVector::Push(Student* s) {
    if (len == capacity) {
        capacity *= 2;
        Student** temp = new Student*[capacity];
        for (size_t i = 0; i < len; i++) {
            temp[i] = p[i];
        }
        delete[] p;
        p = temp;
    }
    p[len++] = s;
}

size_t StudentVector::size() const {
    return len;
}

void StudentVector::SetLen(size_t newLen) {
    if (newLen <= len) {
        len = newLen;
    }
}

Student*& StudentVector::operator[](size_t index) {
    return p[index];
}
