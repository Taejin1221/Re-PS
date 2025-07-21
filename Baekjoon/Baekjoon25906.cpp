// Baekjoon25906.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int money, cost;
    cin >> money >> cost;

    int level[5];
    vector<int> skills[5];
    for (int i = 0; i < 5; i++) {
        cin >> level[i];

        skills[i].push_back(0);
        for (int j = 0; j < level[i]; j++) {
            int temp;
            cin >> temp;

            skills[i].push_back(temp);
        }
    }

    vector<int> price[3];
    vector<vector<int>> armor[3];
    for (int i = 0; i < 3; i++) {
        int m;
        cin >> m;

        price[i].push_back(0);
        for (int j = 1; j <= m; j++) {
            int temp;
            cin >> temp;

            price[i].push_back(temp);
        }

        armor[i].push_back(vector<int> ());
        for (int j = 0; j < 5; j++)
            armor[i][0].push_back(0);

        for (int j = 1; j <= m; j++) {
            armor[i].push_back(vector<int> ());
            for (int k = 0; k < 5; k++) {
                int temp;
                cin >> temp;

                armor[i][j].push_back(temp);
            }
        }
    }

    int ans = 0;
    int x = price[0].size(), y = price[1].size(), z = price[2].size();
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                int totalPrice = price[0][i] + price[1][j] + price[2][k];
                if (totalPrice > money)
                    continue;

                int currLevel[5] = { 0, };
                for (int l = 0; l < 5; l++)
                    currLevel[l] += (armor[0][i][l] + armor[1][j][l] + armor[2][k][l]);

                int damage = 0;
                for (int l = 0; l < 5; l++)
                    damage += skills[l][min(level[l], currLevel[l])];

                int maxDamage = 0;
                if (money - totalPrice >= cost) {
                    for (int ii = 0; ii < 5; ii++) {
                        for (int jj = 0; jj < 5; jj++) {
                            if (ii != jj && (currLevel[ii] < level[ii] && 1 <= currLevel[jj])) {
                                int plus = skills[ii][currLevel[ii] + 1] - skills[ii][currLevel[ii]],
                                    minus = skills[jj][min(level[jj], currLevel[jj])] - skills[jj][min(level[jj], currLevel[jj] - 1)];

                                maxDamage = max(maxDamage, plus - minus);
                            }
                        }
                    }
                }

                damage += maxDamage;

                ans = max(ans, damage);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
