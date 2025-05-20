// Baekjoon29807.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[5] = { 0, };
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    if (arr[0] > arr[2])
        ans += (arr[0] - arr[2]) * 508;
    else
        ans += (arr[2] - arr[0]) * 108;

    if (arr[1] > arr[3])
        ans += (arr[1] - arr[3]) * 212;
    else
        ans += (arr[3] - arr[1]) * 305;

    ans += arr[4] * 707;
    ans *= 4763;

    cout << ans << '\n';

    return 0;
}
