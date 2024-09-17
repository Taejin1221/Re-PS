// Baekjoon01758.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<>());

    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
        sum += max(arr[i] - i, 0);
    }

    cout << sum << '\n';

    return 0;
}