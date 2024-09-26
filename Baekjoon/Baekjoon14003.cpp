// Baekjoon14003.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int search(vector<vector<pii>>& lis, int target) {
    int start = -1, end = lis.size();

    while (start + 1 < end) {
        int mid = (start + end) / 2;

        if (lis[mid].back().first >= target)
            end = mid;
        else
            start = mid;
    }

    return end;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vector<pii>> lis;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int idx = search(lis, num);
        if (idx == lis.size())
            lis.push_back(vector<pii> (1, { num, i }));
        else
            lis[idx].push_back({ num, i });
    }

    cout << lis.size() << '\n';
    
    vector<pii> ans(1, lis.back().back());
    auto iter = lis.rbegin();
    ++iter;
    for (; iter != lis.rend(); ++iter) {
        for (auto i = iter->rbegin(); i != iter->rend(); ++i) {
            if (i->second < ans.back().second) {
                ans.push_back(*i);
                break;
            }
        }
    }

    for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter)
        cout << iter->first << ' ';
    cout << '\n';

    return 0;
}