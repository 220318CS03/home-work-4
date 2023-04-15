#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* qfront;
    Node* qrear;

public:
    Queue() {
        qfront = nullptr;
        qrear = nullptr;
    }

    void enqueue(int n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->next = nullptr;

        if (qrear == nullptr) {
            qfront = newNode;
            qrear = newNode;
        }
        else {
            qrear->next = newNode;
            qrear = newNode;
        }
    }

    void dequeue() {
        if (qfront == nullptr) {
            cout << "Queue is empty" << endl;
        }
        else {
            Node* temp = qfront;
            qfront = qfront->next;
            delete temp;

            if (qfront == nullptr) {
                qrear = nullptr;
            }
        }
    }

    bool isEmpty() {
        return qfront == nullptr;
    }

    int size() {
        int count = 0;
        Node* temp = qfront;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void displayQueue() {
        if (qfront == nullptr) {
            cout << "Queue is empty" << endl;
        }
        else {
            Node* temp = qfront;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int front() {
        if (qfront == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            return qfront->data;
        }
    }

    int back() {
        if (qrear == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            return qrear->data;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.displayQueue();
    q.enqueue(50);
    q.displayQueue();
    q.enqueue(500);
    q.displayQueue();
    cout << q.isEmpty() << endl;
    cout << q.size() << endl;
    q.dequeue();
    q.displayQueue();
    cout << q.isEmpty() << endl;
    cout << q.size() << endl;
    q.enqueue(100);
    q.displayQueue();
    q.dequeue();
    cout << q.front() << " " << q.back() << endl;
    q.dequeue();
    q.displayQueue();
    q.dequeue();
    cout << q.isEmpty() << endl;
    cout << q.size() << endl;

    return 0;
}