// Baekjoon15903.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using ll = long long;

struct compare {
    bool operator()(ll a, ll b) {
        return a > b;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll sum = 0LL;
    priority_queue<ll, vector<ll>, compare> pq;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;

        sum += num;

        pq.push(num);
    }

    while (m--) {
        ll small1 = pq.top(); pq.pop();
        ll small2 = pq.top(); pq.pop();

        ll twoSum = small1 + small2;

        sum += twoSum;

        pq.push(twoSum);
        pq.push(twoSum); 
    }

    cout << sum << '\n';

    return 0;
}