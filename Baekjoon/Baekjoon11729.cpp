// Baekjoon11729.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

vector<pii> ans;

void HanoiTower(int n, int start, int mid, int end) {
    if (n == 1)
        ans.push_back({ start, end });
    else {
        HanoiTower(n - 1, start, end, mid);
        ans.push_back({ start, end });
        HanoiTower(n - 1, mid, start, end);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int n;
    cin >> n;

    HanoiTower(n, 1, 2, 3);

    cout << ans.size() << '\n';
    for (pii& a : ans)
        cout << a.first << ' ' << a.second << '\n';

    return 0;
}