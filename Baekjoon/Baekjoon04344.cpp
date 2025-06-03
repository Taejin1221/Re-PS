// Baekjoon04344.cpp
#include <iostream>

using namespace std;

void solve(void) {
    int n;
    cin >> n;

    double sum = 0.0;
    double arr[1'000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
    }
    double average = sum / n;

    double overAverage = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average)
            overAverage++;
    }

    cout << fixed;
    cout.precision(3);

    cout << (overAverage / n * 100) << "%" << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
