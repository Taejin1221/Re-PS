// Baekjoon02576.cpp
#include <iostream>

using namespace std;

int main(void) {
    int sum = 0, minOdd = 0x3f3f3f3f;
    for (int i = 0; i < 7; i++) {
        int temp;
        cin >> temp;

        if (temp % 2) {
            sum += temp;
            minOdd = min(minOdd, temp);
        }
    }

    if (minOdd == 0x3f3f3f3f)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << minOdd << '\n';

    return 0;
}
