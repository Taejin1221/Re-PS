// Baekjoon11021.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << i << ": " << a + b << '\n';
    }

    return 0;
}