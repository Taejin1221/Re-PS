// Baekjoon16234.cpp
#include <iostream>

#include <queue>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;
using piv = pair<int, vector<pii>>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    int n, l, r;
    cin >> n >> l >> r;

    int people[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> people[i][j];

    int ans = 0;
    while (true) {
        bool visited[50][50] = { { false, }, };
        vector<piv> unites;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;

                    piv uni = { people[i][j], vector<pii>() };
                    uni.second.push_back({ i, j });
                    int idx = 0;
                    while (idx < uni.second.size()) {
                        pii curr = uni.second[idx];

                        for (int k = 0; k < 4; k++) {
                            int nextRow = curr.first + moves[k][0], nextCol = curr.second + moves[k][1];
                            if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) {
                                int diff = ABS(people[curr.first][curr.second] - people[nextRow][nextCol]);
                                if (!visited[nextRow][nextCol] && (l <= diff && diff <= r)) {
                                    visited[nextRow][nextCol] = true;
                                    uni.first += people[nextRow][nextCol];
                                    uni.second.push_back({ nextRow, nextCol });
                                }
                            }
                        }

                        idx++;
                    }

                    unites.push_back(uni);
                }
            }
        }

        if (unites.size() == (n * n))
            break;
        else {
            for (piv& u : unites) {
                int newPeople = u.first / u.second.size();
                for (pii p : u.second)
                    people[p.first][p.second] = newPeople;
            }

            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
