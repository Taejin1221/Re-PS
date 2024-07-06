// Baekjoon02852.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int goalTeam[2'881] = { 0, };
    for (int i = 0; i < n; i++) {
        int team, time = 0;
        char digit;
        cin >> team;

        cin >> digit;
        time += (digit - '0') * 10;
    
        cin >> digit;
        time += digit - '0';

        cin >> digit;
        time *= 60;

        cin >> digit;
        time += (digit - '0') * 10;

        cin >> digit;
        time += digit - '0';

        goalTeam[time] = team;
    }

    int score[3] = { 0, }, ans[3] = { 0, };
    for (int i = 0; i < 2'880; i++) {
        score[goalTeam[i]]++;

        if (score[1] > score[2])
            ans[1]++;
        else if (score[1] < score[2])
            ans[2]++;
    }

    for (int i = 1; i <= 2; i++) {
        int minute = ans[i] / 60;
        if (minute < 10)
            cout << '0';
        cout << minute;
        
        cout << ':';

        int second = ans[i] % 60;
        if (second < 10)
            cout << '0';
        cout << second;

        cout << '\n';
    }

    return 0;
}