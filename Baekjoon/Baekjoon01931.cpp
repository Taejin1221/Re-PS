// Baekjoon01931.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

bool compare(const pii& a, const pii& b) {
    return ((a.second != b.second) ? a.second < b.second : a.first < b.first);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> meetings(n);
    for (int i = 0; i < n; i++)
        cin >> meetings[i].first >> meetings[i].second;
    sort(meetings.begin(), meetings.end(), compare);

    int ans = 1;
    pii curr = meetings[0];
    for (int i = 1; i < n; i++) {
        if (curr.second <= meetings[i].first) {
            ans++;
            curr = meetings[i];
        }
    }

    cout << ans << '\n';

    return 0;
}