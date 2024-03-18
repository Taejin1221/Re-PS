// Baekjoon10866.cpp
#include <iostream>

#include <string>

using namespace std;

struct Node {
    int val;
    Node* next, * prev;

    Node(int v, Node* n, Node* p): val(v), next(n), prev(p) { }
};

class Deque {
    int size;
    Node* front, * rear;
public:
    Deque(): front(NULL), rear(NULL), size(0) { }

    void pushFront(int x) {
        Node* newNode = new Node(x, front, NULL);
        if (size == 0)
            rear = newNode;
        else
            front->prev = newNode;
        front = newNode;

        size++;
    }

    void pushBack(int x) {
        Node* newNode = new Node(x, NULL, rear);
        if (size == 0)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;

        size++;
    }

    int popFront() {
        if (size == 0)
            return -1;
        else {
            int result = front->val;
            Node* temp = front;
            if (size == 1)
                front = rear = NULL;
            else {
                front->next->prev = NULL;
                front = front->next;
            }

            delete temp;
            size--;

            return result;
        }
    }

    int popBack() {
         if (size == 0)
            return -1;
        else {
            int result = rear->val;
            Node* temp = rear;
            if (size == 1)
                front = rear = NULL;
            else {
                rear->prev->next = NULL;
                rear = rear->prev;
            }

            delete temp;
            size--;

            return result;
        }
    }

    int getSize() { return size; }

    int isEmpty() { return size == 0; }

    int getFront() {
        return (size ? front->val : -1);
    }

    int getBack() {
        return (size ? rear->val : -1);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    Deque dq = Deque();
    while (t--) {
        string opr;
        cin >> opr;

        if (opr == "push_front") {
            int x;
            cin >> x;

            dq.pushFront(x);
        } else if (opr == "push_back") {
            int x;
            cin >> x;

            dq.pushBack(x);
        } else if (opr == "pop_front") {
            cout << dq.popFront() << '\n';
        } else if (opr == "pop_back") {
            cout << dq.popBack() << '\n';
        } else if (opr == "size") {
            cout << dq.getSize() << '\n';
        } else if (opr == "empty") {
            cout << dq.isEmpty() << '\n';
        } else if (opr == "front") {
            cout << dq.getFront() << '\n';
        } else if (opr == "back") {
            cout << dq.getBack() << '\n';
        }
    }

    return 0;
}