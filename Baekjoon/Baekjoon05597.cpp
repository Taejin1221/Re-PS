// Baekjoon05597.cpp
#include <iostream>

using namespace std;

int main(void) {
    bool students[31] = { false, };
    for (int i = 0; i < 28; i++) {
        int num;
        cin >> num;

        students[num] = true;
    }

    for (int i = 1; i <= 30; i++)
        if (!students[i])
            cout << i << '\n';

    return 0;
}