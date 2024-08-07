// Baekjoon16938.cpp
#include <iostream>

using namespace std;

int n, l, r, x;
int ans;
int problems[15], visited[32'768];

void dfs(int curr, int probSum, int currSelect, int levelSum, int easiest, int hardest) {
    if (levelSum > r)
        return;
    else if (levelSum >= l && probSum >= 2 && (hardest - easiest) >= x) {
        if (!visited[currSelect]) {
            visited[currSelect] = true;
            ans++;
        }
    }

    if (curr < n) {
        dfs(curr + 1, probSum, currSelect, levelSum, easiest, hardest);
        dfs(curr + 1, probSum + 1, currSelect | (1 << curr),  levelSum + problems[curr], min(easiest, problems[curr]), max(hardest, problems[curr]));
    }
}

int main(void) {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
        cin >> problems[i];

    dfs(0, 0, 0, 0, 0x3f3f3f3f, 0);

    cout << ans << '\n';

    return 0;
}