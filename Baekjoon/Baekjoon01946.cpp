// Baekjoon01946.cpp
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    pii scores[100'000];
    for (int i = 0; i < n; i++)
        cin >> scores[i].first >> scores[i].second;
    sort(scores, scores + n);

    int ans = 1, minSecondScore = scores[0].second;
    for (int i = 1; i < n; i++) {
        if (minSecondScore > scores[i].second) {
            ans++;
            minSecondScore = scores[i].second;
        }
    }

    cout << ans << '\n';    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}