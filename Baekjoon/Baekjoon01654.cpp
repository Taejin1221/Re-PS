// Baekjoon01654.cpp
#include <iostream>

#include <vector>
#include <climits>

using namespace std;

using ll = long long;

int cutLAN(vector<int>& cable, int len) {
    int result = 0;
    for (int c : cable)
        result += c / len;

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    ll start = 1, end = (ll)1 << 32;
    vector<int> cable(n);
    for (int i = 0; i < n; i++)
        cin >> cable[i];

    while (start + 1 < end) {
        ll mid = (start + end) / 2;

        if (cutLAN(cable, mid) >= k)
            start = mid;
        else
            end = mid;
    }

    cout << start << '\n';

    return 0;
}