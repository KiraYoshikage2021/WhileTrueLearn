#ifndef PQ_H
#define PQ_H

#include <iostream>

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;

    Node(int val) : data(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

class PQ {
private:
    Node* head; 
    Node* tail;
    int count; 

    
    void bubbleUp(Node* node);
    void bubbleDown(Node* node);
    void swapValues(Node* a, Node* b);
    
   
    Node* getNodeByIndex(int index);

public:
    PQ();
    ~PQ();

    void push(int val);
    int pop();
    bool empty();
};

#endif

