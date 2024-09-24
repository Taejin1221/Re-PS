// Baekjoon32298.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cout << m * (i + 2) << ' ';
    cout << '\n';

    return 0;
}