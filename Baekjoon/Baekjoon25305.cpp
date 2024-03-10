// Baekjoon25305.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<>());

    cout << arr[k - 1] << '\n';

    return 0;
}