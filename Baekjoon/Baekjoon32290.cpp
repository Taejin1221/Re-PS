// Baekjoon32290.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int l, r, x;
    cin >> l >> r >> x;

    vector<int> arr;
    for (int i = l; i <= r; i++)
        arr.push_back(i | x);
    sort(arr.begin(), arr.end());

    int ans, arrIdx = 0;
    for (ans = 0; ans == arr[arrIdx]; ans++)
        arrIdx++;

    cout << ans << '\n';

    return 0;
}
