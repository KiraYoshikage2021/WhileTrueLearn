#include <iostream>
#include <cstdlib> 
#include "PQ.h"

using namespace std;

int main() {
    PQ q;

    for (int i = 0; i < 1000; i++) {
        q.push(rand());
    }

    while (!q.empty()) {
        cout << q.pop() << " ";
    }

    cout << endl;
    return 0;
}
