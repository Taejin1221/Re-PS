// Baekjoon10845.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int front = 0, rear = 0, arr[10'000];
    while (n--) {
        string opr;
        cin >> opr;

        if (opr == "push") {
            int x;
            cin >> x;

            arr[rear++] = x;
        } else if (opr == "pop")
            cout << (front != rear ? arr[front++] : -1) << '\n';
        else if (opr == "size")
            cout << rear - front << '\n';
        else if (opr == "empty")
            cout << ((rear - front) == 0) << '\n';
        else if (opr == "front")
            cout << (front != rear ? arr[front] : -1) << '\n';
        else if (opr == "back")
            cout << (front != rear ? arr[rear - 1] : -1) << '\n';
    }

    return 0;
}