#include "PQ.h"
#include <stdexcept>

PQ::PQ() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

void deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

PQ::~PQ() {
    deleteTree(head);
}

bool PQ::empty() {
    return count == 0;
}

void PQ::swapValues(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* PQ::getNodeByIndex(int index) {
    if (index <= 0 || index > count) return nullptr;
    if (index == 1) return head;


    int highestBit = 0;
    for (int i = 0; i < 31; i++) {
        if ((index >> i) == 1) {
            highestBit = i;
            break;
        }
    }

    Node* curr = head;

    for (int i = highestBit - 1; i >= 0; i--) {
        int bit = (index >> i) & 1;
        if (bit == 0) {
            curr = curr->right; 
        } else {
            curr = curr->left;  
        }
    }
    return curr;
}

void PQ::push(int val) {
    Node* newNode = new Node(val);
    
    if (count == 0) {
        head = newNode;
        tail = newNode;
        count++;
        return;
    }

    count++; 
    
    
    Node* parent = getNodeByIndex(count / 2);
    
    newNode->parent = parent;
    

    if (count % 2 == 0) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
    
    tail = newNode; 
    bubbleUp(tail); 
}

void PQ::bubbleUp(Node* node) {

    while (node->parent && node->data > node->parent->data) {
        swapValues(node, node->parent);
        node = node->parent;
    }
}

int PQ::pop() {
    if (empty()) {
        std::cerr << "Error: PQ is empty" << std::endl;
        exit(1);
    }

    int retVal = head->data;

    if (count == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        count = 0;
        return retVal;
    }


    swapValues(head, tail);


    Node* oldTail = tail;
    Node* parent = oldTail->parent;

    if (parent->right == oldTail) parent->right = nullptr;
    else parent->left = nullptr;

    delete oldTail;
    count--;


    tail = getNodeByIndex(count);


    bubbleDown(head);

    return retVal;
}

void PQ::bubbleDown(Node* node) {
    while (true) {
        Node* largest = node;
        Node* right = node->right;
        Node* left = node->left;


        if (right && right->data > largest->data) {
            largest = right;
        }

        if (left && left->data > largest->data) {
            largest = left;
        }

        if (largest != node) {
            swapValues(node, largest);
            node = largest;
        } else {
            break;
        }
    }
}

