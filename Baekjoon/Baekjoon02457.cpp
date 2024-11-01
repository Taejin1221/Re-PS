// Baekjoon02457.cpp
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

const int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 미리 각 월까지의 일수 합을 구해놓음
    int monthSum[13] = { 0, 0, };
    for (int i = 2; i <= 12; i++)
        monthSum[i] = monthSum[i - 1] + days[i - 1];

    // 3월 1일, 11월 30일
    pii season = { monthSum[3] + 1, monthSum[11] + 30 };

    int n;
    cin >> n;

    pii flowers[100'000];
    for (int i = 0; i < n; i++) {
        pii start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        // 입력과 동시에 총 일수로 계산
        flowers[i] = { monthSum[start.first] + start.second, monthSum[end.first] + end.second };
    }
    sort(flowers, flowers + n); // 꽃이 핀 날짜로 정렬

    int dp[366];
    fill(dp, dp + 366, 0x3f3f3f3f);
    for (int i = n - 1; i >= 0; i--) {
        int start = flowers[i].first, end = flowers[i].second;
        // 3월 1일 보다 일찍 지고, 11월 30일 보다 늦게 피는 꽃은 필요없음
        if (end < season.first || season.second < start)
            continue;

        // 만약 현재 선택한 꽃이 11월 30일 이상까지 피어있다면 1
        if (season.second < end)
            dp[start] = 1;
        else
            for (int j = flowers[i].first; j <= flowers[i].second; j++)
                dp[start] = min(dp[start], dp[j] + 1);
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= season.first; i++)
        ans = min(ans, dp[i]);

    if (ans == 0x3f3f3f3f)
        cout << 0;
    else
        cout << ans;
    cout << '\n';

    return 0;
}