// Baekjoon24511.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first;
    for (int i = 0; i < n; i++)
        cin >> arr[i].second;

    queue<int> ans;
    for (auto iter = arr.rbegin(); iter != arr.rend(); ++iter)
        if (iter->first == 0)
            ans.push(iter->second);
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        ans.push(c);
        cout << ans.front() << ' ';
        ans.pop();
    }
    cout << '\n';

    return 0;
}