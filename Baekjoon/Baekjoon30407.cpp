// Baekjoon30407.cpp
#include <iostream>

using namespace std;

int n, k, damage[18];
int ans;

void solve(int idx, int chunbae, int distance, bool use) {
    if (chunbae <= 0)
        return;

    if (idx > n)
        return;

    if (idx == n)
        ans = max(ans, chunbae);
    else {
        int nextDamage = (damage[idx] > distance) ? damage[idx] - distance : 0;
        // 깜짝 놀라게 하기 사용
        if (!use)
            solve(idx + 2, chunbae - nextDamage, distance + k, true);

        // 웅크리기 사용
        solve(idx + 1, chunbae - nextDamage / 2, distance, use);

        // 네발로 걷기 사용
        int nextDis = distance + k;
        nextDamage = (damage[idx] > nextDis) ? damage[idx] - nextDis : 0;

        solve(idx + 1, chunbae - nextDamage, nextDis, use);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int chunbae, distance;
    cin >> chunbae >> distance >> k;

    for (int i = 0; i < n; i++)
        cin >> damage[i];

    solve(0, chunbae, distance, false);

    cout << (ans <= 0 ? -1 : ans) << '\n';

    return 0;
}
