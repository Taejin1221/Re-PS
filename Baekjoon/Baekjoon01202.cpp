// Baekjoon01202.cpp
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    pii jewerlies[300'000];
    for (int i = 0; i < n; i++)
        cin >> jewerlies[i].first >> jewerlies[i].second;
    sort(jewerlies, jewerlies + n);
    
    int bag[300'000];
    for (int i = 0; i < k; i++)
        cin >> bag[i];
    sort(bag, bag + k);

    priority_queue<int> pq;
    int jewerlyIdx = 0; ll ans = 0LL;
    for (int bagIdx = 0; bagIdx < k; bagIdx++) {
        while (jewerlyIdx < n && jewerlies[jewerlyIdx].first <= bag[bagIdx]) {
            pq.push(jewerlies[jewerlyIdx].second);
            jewerlyIdx++;
        }

        if (!pq.empty()) {
            ans = ans + pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}