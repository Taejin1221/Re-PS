// Baekjoon11895.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int xorSum = 0, sum = 0, minVal = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        minVal = min(minVal, temp);
        sum += temp;
        xorSum ^= temp;
    }

    xorSum ^= minVal;
    if (xorSum == minVal)
        cout << sum - minVal;
    else
        cout << 0;
    cout << '\n';

    return 0;
}
