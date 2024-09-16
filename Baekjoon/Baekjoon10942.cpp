// Baekjoon10942.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[2'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool dp[2'000][2'000] = { { false, }, };
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = arr[i] == arr[i + 1];

    for (int len = 2; len < n; len++) { // len: 체크할 배열의 길이
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            if (arr[i] == arr[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> start >> end;

        start--, end--;
        cout << (dp[start][end] ? 1 : 0) << '\n';
    }

    return 0;
}