#include <iostream>
using namespace std;
#define MAX 5

class LIST {
public:
    virtual void store(int value) = 0;    
    virtual int retrieve() = 0;        
};

class Stack : public LIST {
    int arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }

    void store(int value) override {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot store " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Stored " << value << " in Stack." << endl;
    }

    int retrieve() override {
        if (top < 0) {
            cout << "Stack Underflow! ";
            return -1;
        }
        return arr[top--];
    }
};

class Queue : public LIST {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void store(int value) override {
        if (rear >= MAX - 1) {
            cout << "Queue Overflow!" << value << endl;
            return;
        }
        arr[++rear] = value;
        cout << "Stored " << value << " in Queue." << endl;
    }

    int retrieve() override {
        if (front > rear) {
            cout << "Queue Underflow! ";
            return -1;
        }
        return arr[front++];
    }
};

int main() {
    LIST* listPtr;

    Stack St;
    listPtr = &St;
    listPtr->store(10);
    listPtr->store(20);
    listPtr->store(30);
    cout << "Retrieved from Stack: " << listPtr->retrieve() << endl;
    cout << "Retrieved from Stack: " << listPtr->retrieve() << endl;

    Queue Q;
    listPtr = &Q;
    listPtr->store(100);
    listPtr->store(200);
    listPtr->store(300);
    cout << "Retrieved from Queue: " << listPtr->retrieve() << endl;
    cout << "Retrieved from Queue: " << listPtr->retrieve() << endl;

    return 0;
}
