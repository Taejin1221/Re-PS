// Baekjoon02566.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int maxVal = -1;
    pii maxPos = { -1, -1 };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int temp;
            cin >> temp;

            if (maxVal < temp) {
                maxVal = temp;
                maxPos = { i + 1, j + 1 };
            }
        }
    }

    cout << maxVal << '\n';
    cout << maxPos.first << ' ' << maxPos.second << '\n';

    return 0;
}