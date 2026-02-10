// Baekjoon05545.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int c;
    cin >> c;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int ans = c / a, sum = c;
    for (int i = 1; i <= n; i++) {
        sum += arr[n - i];
        int temp = sum / (a + b * i);
        ans = max(ans, temp);
    }
    cout << ans << '\n';

    return 0;
}
