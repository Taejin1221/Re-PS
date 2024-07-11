// Baekjoon16463.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int endDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // day = { 0: sunday, 1: monday:, ..., 6: saturday }
    int year = 2019, month = 1, day = 2;

    int n;
    cin >> n;

    int ans = 0;
    while (!(year == n && month == 12)) {
        day = day + endDay[month];
        if (month == 2)
            if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
                day++;
        day %= 7;

        if (month == 12)
            year++, month = 0;
        month++;

        if (day == 0)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}