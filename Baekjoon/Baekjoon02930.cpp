// Baekjoon02930.cpp
#include <iostream>

#include <string>

using namespace std;

int 가위바위보(char a, char b) {
    if (a == 'R') {
        if (b == 'R')
            return 1;
        else if (b == 'S')
            return 2;
        else
            return 0;
    } else if (a == 'S') {
        if (b == 'R')
            return 0;
        else if (b == 'S')
            return 1;
        else
            return 2;
    } else {
        if (b == 'R')
            return 2;
        else if (b == 'S')
            return 0;
        else
            return 1;
    }
}

int main(void) {
    int r;
    cin >> r;

    string 상근;
    cin >> 상근;

    int n;
    cin >> n;

    string friends[50];
    for (int i = 0; i < n; i++)
        cin >> friends[i];

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < r; i++) {
        int if상근[3] = { 0, 0, 0 };
        for (int j = 0; j < n; j++) {
            ans1 += 가위바위보(상근[i], friends[j][i]);
            if상근[0] += 가위바위보('R', friends[j][i]);
            if상근[1] += 가위바위보('S', friends[j][i]);
            if상근[2] += 가위바위보('P', friends[j][i]);
        }

        ans2 += max(if상근[0], max(if상근[1], if상근[2]));
    }

    cout << ans1 << '\n' << ans2 << '\n';

    return 0;
}