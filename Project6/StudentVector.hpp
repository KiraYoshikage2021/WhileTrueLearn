#ifndef STUDENTVECTOR_HPP
#define STUDENTVECTOR_HPP

#include "Student.hpp"
#include <cstddef> // for size_t

class StudentVector {
private:
    Student** p;     
    size_t capacity; 
    size_t len;      

public:
    StudentVector();
    ~StudentVector();
    
    void Clear(); // Sets len to 0, does not delete objects
    void Push(Student* s);
    size_t size() const; 
    void SetLen(size_t newLen);

    Student*& operator[](size_t index);
};

#endif
