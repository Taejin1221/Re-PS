#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    queue<pii> q;
    vector<int> a, b, c;

    int t;
    cin >> t;
    while (t--) {
        int o;
        cin >> o;
        
        if (o == 1) {
            int n, food;
            cin >> n >> food;

            q.push({ n, food });
        } else {
            int food;
            cin >> food;

            pii curr = q.front(); q.pop();
            if (curr.second == food)
                a.push_back(curr.first);
            else
                b.push_back(curr.first);
        }
    }

    while (!q.empty()) {
        c.push_back(q.front().first);
        q.pop();
    }

    sort(a.begin(), a.end());
    if (a.empty())
        cout << "None";
    else {
        for (int& i : a)
            cout << i << ' ';
    }
    cout << '\n';

    sort(b.begin(), b.end());
    if (b.empty())
        cout << "None";
    else {
        for (int& i : b)
            cout << i << ' ';
    }
    cout << '\n';

    sort(c.begin(), c.end());
    if (c.empty())
        cout << "None";
    else {
        for (int& i : c)
            cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
