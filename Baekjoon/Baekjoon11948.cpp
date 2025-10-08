// Baekjoon11948.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    int arr[4];
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    sort(arr, arr + 4);

    int arr2[2];
    for (int i = 0; i < 2; i++)
        cin >> arr2[i];
    sort(arr2, arr2 + 2);

    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans += arr[4 - i];
    ans += arr2[1];

    cout << ans << '\n';

    return 0;
}
