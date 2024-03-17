// Baekjoon11866.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    vector<int> ans(n);
    for (int idx = 0; q.size(); idx++) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        ans[idx] = q.front();
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << ", ";
    cout << ans.back() << ">\n";

    return 0;
}