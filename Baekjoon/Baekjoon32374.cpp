// Baekjoon32374.cpp
#include <iostream>

#include <map>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int presents[200'000];
    for (int i = 0; i < n; i++)
        cin >> presents[i];
    sort(presents, presents + n);

    map<int, int> boxes;
    for (int i = 0; i < n; i++) {
        int box;
        cin >> box;

        auto findBox = boxes.find(box);
        if (findBox == boxes.end())
            boxes.insert({ box, 1 });
        else
            findBox->second++;
    }

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;

        auto findBox = boxes.find(c);

        findBox->second--;
        if (findBox->second == 0)
            boxes.erase(findBox);
    }

    int myBox = boxes.rbegin()->first;
    int idx = lower_bound(presents, presents + n, myBox) - presents;

    int ans;
    if (idx == n || myBox < presents[idx])
        ans = presents[idx - 1];
    else if (myBox == presents[idx])
        ans = presents[idx];

    cout << ans << '\n';

    return 0;
}