// Baekjoon16722.cpp
#include <iostream>

#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool isAllSame(string& a, string& b, string& c) {
    return (a == b && b == c && c == a);
}

bool isAllDiff(string& a, string& b, string& c) {
    return (a != b && b != c && c != a);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string paint[10][3];
    for (int i = 1; i <= 9; i++)
        cin >> paint[i][0] >> paint[i][1] >> paint[i][2];

    set<string> combination;
    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            for (int k = j + 1; k <= 9; k++) {
                if (isAllSame(paint[i][0], paint[j][0], paint[k][0]) || isAllDiff(paint[i][0], paint[j][0], paint[k][0])) {
                    if (isAllSame(paint[i][1], paint[j][1], paint[k][1]) || isAllDiff(paint[i][1], paint[j][1], paint[k][1])) {
                        if (isAllSame(paint[i][2], paint[j][2], paint[k][2]) || isAllDiff(paint[i][2], paint[j][2], paint[k][2])) {
                            string temp = "";

                            temp.push_back('0' + i);
                            temp.push_back('0' + j);
                            temp.push_back('0' + k);
                            combination.insert(temp);
                        
                        }
                    }
                }
            }
        }
    }

    int t;
    cin >> t;

    int score = 0;
    bool gyeol = false;
    while (t--) {
        char oper;
        cin >> oper;

        if (oper == 'H') {
            int temp[3];
            cin >> temp[0] >> temp[1] >> temp[2];

            sort(temp, temp + 3);

            string query = "";
            query.push_back('0' + temp[0]);
            query.push_back('0' + temp[1]);
            query.push_back('0' + temp[2]);

            if (combination.find(query) != combination.end()) {
                score += 1;
                combination.erase(query);
            } else
                score -= 1;
        } else {
            if (combination.size() == 0 && !gyeol) {
                score += 3;
                gyeol = true;
            } else
                score -= 1;
        }
    }

    cout << score << '\n';

    return 0;
}
