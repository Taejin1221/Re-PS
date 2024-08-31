// Baekjoon30917.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a = -1;
    for (int i = 1; a == -1; i++) {
        cout << "? A " << i << endl;

        int answer;
        cin >> answer;

        if (answer == 1)
            a = i;
    }

    int b = -1;
    for (int i = 1; b == -1; i++) {
        cout << "? B " << i << endl;

        int answer;
        cin >> answer;

        if (answer == 1)
            b = i;
    }

    cout << "! " << a + b << endl;

    return 0;
}