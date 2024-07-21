// Baekjoon20167.cpp
#include <iostream>

using namespace std;

int n, k, food[20];

int dfs(int idx, int curr, int total, bool isEat) {
    if (idx == n)
        return total;
    else {
        int result = 0;
        int currScore = curr + food[idx];
        if (currScore >= k)
            result = max(result, dfs(idx + 1, 0, total + currScore - k, false));
        else
            result = max(result, dfs(idx + 1, currScore, total, true));

        if (!isEat)
            result = max(result, dfs(idx + 1, curr, total, false));

        return result;
    }
}

int main(void) {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> food[i];

    cout << dfs(0, 0, 0, false) << '\n';

    return 0;
}