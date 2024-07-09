// Baekjoon02096.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pii score[3][2];
    cin >> score[0][0].first >> score[1][0].first >> score[2][0].first;
    score[0][0].second = score[0][0].first;
    score[1][0].second = score[1][0].first;
    score[2][0].second = score[2][0].first;
    for (int i = 1; i < n; i++) {
        int curr[3];
        cin >> curr[0] >> curr[1] >> curr[2];

        score[0][1].first = max(score[0][0].first, score[1][0].first) + curr[0];
        score[0][1].second = min(score[0][0].second, score[1][0].second) + curr[0];

        score[1][1].first = max(score[0][0].first, max(score[1][0].first, score[2][0].first)) + curr[1];
        score[1][1].second = min(score[0][0].second, min(score[1][0].second, score[2][0].second)) + curr[1];

        score[2][1].first = max(score[1][0].first, score[2][0].first) + curr[2];
        score[2][1].second = min(score[1][0].second, score[2][0].second) + curr[2];

        score[0][0] = score[0][1];
        score[1][0] = score[1][1];
        score[2][0] = score[2][1];
    }

    cout << max(score[0][0].first, max(score[1][0].first, score[2][0].first)) << ' ';
    cout << min(score[0][0].second, min(score[1][0].second, score[2][0].second)) << '\n';

    return 0;
}