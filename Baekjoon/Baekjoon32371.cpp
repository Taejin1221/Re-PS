// Baekjoon32371.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string keyboard[4];
    cin >> keyboard[0];
    cin >> keyboard[1];
    cin >> keyboard[2];
    cin >> keyboard[3];

    string memo;
    cin >> memo;

    vector<pii> ans;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 10; k++) {
                if (memo[i] == keyboard[j][k])
                    ans.push_back({ j, k });
            }
        }
    }

    sort(ans.begin(), ans.end());

    pii mid = ans[4];
    cout << keyboard[mid.first][mid.second] << '\n';

    return 0;
}