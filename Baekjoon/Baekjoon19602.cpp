// Baekjoon19602.cpp
#include <iostream>

using namespace std;

int main(void) {
    int s, m, l;
    cin >> s >> m >> l;

    int ans = s + 2 * m + 3 * l;
    if (ans < 10)
        cout << "sad";
    else
        cout << "happy";
    cout << '\n';

    return 0;
}
