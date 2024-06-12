// Baekjoon02526.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, p;
    cin >> n >> p;

    int table[1'001] = { 0, };
    int curr = n;
    table[curr] = 1;
    while (table[curr] <= 2) {
        curr *= n;
        curr %= p;

        table[curr]++;
    }

    int ans = 0;
    for (int i = 0; i <= p; i++)
        if (table[i] >= 2)
            ans++;

    cout << ans << '\n';

    return 0;
}