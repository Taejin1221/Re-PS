// Baekjoon02568.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

bool compare(pii a, int b) {
    return a.first < b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    pii arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);

    vector<pii> lis;
    int path[100'000];
    for (int i = 0; i < n; i++) {
        int currIdx = lower_bound(lis.begin(), lis.end(), arr[i].second, compare) - lis.begin();

        if (currIdx == lis.size())
            lis.push_back({ arr[i].second, i });
        else
            lis[currIdx] = { arr[i].second, i };

        if (currIdx == 0)
            path[i] = -1;
        else
            path[i] = lis[currIdx - 1].second;
    }

    vector<int> lisList;
    bool isInLis[100'000] = { false, };
    for (int i = lis.back().second; i != -1; i = path[i]) {
        lisList.push_back(i);
        isInLis[i] = true;
    }

    cout << n - lisList.size() << '\n';
    for (int i = 0; i < n; i++)
        if (!isInLis[i])
            cout << arr[i].first << '\n';

    return 0;
}