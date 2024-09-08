// Baekjoon01026.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a[50], b[50];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[n - i - 1];

    cout << sum << '\n';

    return 0;
}