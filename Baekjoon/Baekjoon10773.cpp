// Baekjoon10773.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    vector<int> stck;
    while (t--) {
        int k;
        cin >> k;

        k ? stck.push_back(k) : stck.pop_back();
    }

    int ans = 0;
    for (int& s : stck)
        ans += s;

    cout << ans << '\n';

    return 0;
}