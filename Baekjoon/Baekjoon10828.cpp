// Baekjoon10828.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int top = 0, stck[10'000];
    for (int i = 0; i < n; i++) {
        string opr;
        cin >> opr;

        if (opr == "push") {
            int x;
            cin >> x;

            stck[top++] = x;
        } else if (opr == "pop") {
            cout << (top != 0 ? stck[--top] : -1) << '\n';
        } else if (opr == "size") {
            cout << top << '\n';
        } else if (opr == "empty") {
            cout << (top == 0) << '\n';
        } else if (opr == "top") {
            cout << (top != 0 ? stck[top - 1] : -1) << '\n';
        }
    }

    return 0;
}