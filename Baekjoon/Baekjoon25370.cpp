#include <iostream>

#define MAX 5'000'000

using namespace std;

int n, ans = 0;
bool isIn[MAX];

void dfs(int curr, int mul) {
    if (curr == n) {
        if (!isIn[mul]) {
            isIn[mul] = true;
            ans++;
        }
    } else {
        for (int i = 1; i <= 9; i++)
            dfs(curr + 1, mul * i);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    dfs(0, 1);

    cout << ans << '\n';

    return 0;
}
