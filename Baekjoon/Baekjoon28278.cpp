// Baekjoon28278.cpp
#include <iostream>

using namespace std;

class Stack {
    int idx, arr[1'000'000];

public:
    Stack(): idx(0) { }

    void push(int x) {
        arr[idx++] = x;
    }

    int pop() {
        return idx ? arr[--idx] : -1;
    }

    int size() {
        return idx;
    }

    int isEmpty() {
        return idx == 0;
    }

    int top() {
        return idx ? arr[idx - 1] : -1;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    Stack stck = Stack();
    while (t--) {
        int opr;
        cin >> opr;

        if (opr == 1) {
            int x;
            cin >> x;

            stck.push(x);
        } else if (opr == 2) {
            cout << stck.pop() << '\n';
        } else if (opr == 3) {
            cout << stck.size() << '\n';
        } else if (opr == 4) {
            cout << stck.isEmpty() << '\n';
        } else if (opr == 5) {
            cout << stck.top() << '\n';
        }
    }

    return 0;
}