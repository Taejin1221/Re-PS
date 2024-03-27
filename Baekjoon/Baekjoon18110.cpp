// Baekjoon18110.cpp
#include <iostream>

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';

        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int cut = (int)round(n * 0.15);

    double result = 0.0;
    for (int i = cut; i < n - cut; i++)
        result += arr[i];
    cout << (int)round(result / (n - cut * 2)) << '\n';

    return 0;
}