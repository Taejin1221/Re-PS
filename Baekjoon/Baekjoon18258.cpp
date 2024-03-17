// Baekjoon18258.cpp
#include <iostream>

#include <string>

using namespace std;

class Queue {
    int front, rear, size;
    int arr[2'000'000];
public:
    Queue(): front(0), rear(0), size(0) { }

    void push(int x) {
        arr[rear++] = x;
        size++;
    }

    int pop() {
        if (size == 0)
            return -1;
        else {
            size--;
            return arr[front++];
        }
    }

    int empty() { return size == 0; }
    int getSize() { return size; }
    int getFront() { return (size == 0 ? -1 : arr[front]); }
    int getBack() { return (size == 0 ? -1 : arr[rear - 1]); }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    Queue q = Queue();
    while (t--) {
        string opr;
        cin >> opr;
        if (opr == "push") {
            int x;
            cin >> x;

            q.push(x);
        } else if (opr == "pop")
            cout << q.pop() << '\n';
        else if (opr == "size")
            cout << q.getSize() << '\n';
        else if (opr == "empty")
            cout << q.empty() << '\n';
        else if (opr == "front")
            cout << q.getFront() << '\n';
        else if (opr == "back")
            cout << q.getBack() << '\n';
    }

    return 0;
}