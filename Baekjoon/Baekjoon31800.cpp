// Baekjoon31800.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int revenue[300'000], most = 0, more = 0;
    for (int i = 0; i < n; i++) {
        cin >> revenue[i];

        if (most <= revenue[i]) {
            more = most;
            most = revenue[i];
        } else if (more <= revenue[i])
            more = revenue[i];
    }

    int price[300'000];
    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++) {
        int opp = (revenue[i] != most ? most : more) - price[i];
        int pure = revenue[i] - opp - price[i];

        cout << pure << ' ';
    }
    cout << '\n';

    return 0;
}
