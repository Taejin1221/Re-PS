// Baekjoon11659.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> arr(n), prefix(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    while (t--) {
        int i, j;
        cin >> i >> j;

        cout << prefix[j] - prefix[i - 1] << '\n';
    }

    return 0;
}