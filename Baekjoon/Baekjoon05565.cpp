// Baekjoon05565.cpp
#include <iostream>

using namespace std;

int main(void) {
    int sum;
    cin >> sum;

    for (int i = 0; i < 9; i++) {
        int p;
        cin >> p;

        sum -= p;
    }

    cout << sum << '\n';

    return 0;
}
