// Baekjoon01715.cpp
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        pq.push(temp);
    }

    int ans = 0;
    while (pq.size() > 1) {
        int temp1 = pq.top(); pq.pop();
        int temp2 = pq.top(); pq.pop();

        ans += temp1 + temp2;

        pq.push(temp1 + temp2);
    }

    cout << ans << '\n';

    return 0;
}
