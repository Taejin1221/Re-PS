// Baekjoon02484.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int arr[4];
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        sort(arr, arr + 4);

        int score;
        if (arr[0] == arr[3])
            score = 50000 + arr[0] * 5000;
        else if (arr[0] == arr[2] || arr[1] == arr[3])
            score = 10000 + arr[1] * 1000;
        else if (arr[0] == arr[1] && arr[2] == arr[3])
            score = 2000 + arr[0] * 500 + arr[2] * 500;
        else if (arr[0] == arr[1])
            score = 1000 + arr[0] * 100;
        else if (arr[1] == arr[2])
            score = 1000 + arr[1] * 100;
        else if (arr[2] == arr[3])
            score = 1000 + arr[2] * 100;
        else
            score = arr[3] * 100;

        ans = max(ans, score);
    }

    cout << ans << '\n';

    return 0;
}
