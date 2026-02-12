// Baekjoon28136.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[1'000'001];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = arr[0];

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] >= arr[i + 1])
            ans++;

    cout << ans << '\n';

    return 0;
}
