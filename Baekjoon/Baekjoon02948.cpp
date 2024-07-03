// Baekjoon02948.cpp
#include <iostream>

using namespace std;

int main(void) {
    int months[13] = { 0, };
    months[1] = months[0] + 31;
    months[2] = months[1] + 28;
    months[3] = months[2] + 31;
    months[4] = months[3] + 30;
    months[5] = months[4] + 31;
    months[6] = months[5] + 30;
    months[7] = months[6] + 31;
    months[8] = months[7] + 31;
    months[9] = months[8] + 30;
    months[10] = months[9] + 31;
    months[11] = months[10] + 30;
    months[12] = months[11] + 31;

    string ans[7] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday" };

    int m, d;
    cin >> d >> m;

    int day = months[m - 1] + d;
    cout << ans[day % 7] << '\n';

    return 0;
}