// Baekjoon15702.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int scores[100];
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    pair<int, int> ans = { 0x3f3f3f3f, 0 };
    for (int i = 0; i < m; i++) {
        int id, currScore = 0;
        cin >> id;

        for (int i = 0; i < n; i++) {
            char o;
            cin >> o;

            if (o == 'O')
                currScore += scores[i];
        }

        if ((ans.second < currScore) || (ans.second == currScore && ans.first > id))
            ans = { id, currScore };
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}