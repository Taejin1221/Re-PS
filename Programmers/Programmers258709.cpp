// Programmers258709.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, half;
pair<int, vector<int>> maxChoice;

void getSumList(vector<vector<int>>& dice, vector<int>& sum, vector<int>& choice) {
    int size = choice.size();
    for (int i = 0; i < 6; i++) {
        if (size == 1)
            sum.push_back(dice[choice[0]][i]);
        else {
            for (int j = 0; j < 6; j++) {
                if (size == 2)
                    sum.push_back(dice[choice[0]][i] + dice[choice[1]][j]);
                else {
                    for (int k = 0; k < 6; k++) {
                        if (size == 3)
                            sum.push_back(dice[choice[0]][i] + dice[choice[1]][j] + dice[choice[2]][k]);
                        else {
                            for (int l = 0; l < 6; l++) {
                                if (size == 4)
                                    sum.push_back(dice[choice[0]][i] + dice[choice[1]][j] + dice[choice[2]][k] + dice[choice[3]][l]);
                                else {
                                    for (int m = 0; m < 6; m++) {
                                        sum.push_back(dice[choice[0]][i] + dice[choice[1]][j] + dice[choice[2]][k] + dice[choice[3]][l] + dice[choice[4]][m]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void dfs(vector<vector<int>>& dice, int curr, vector<int> choices[]) {
    if (choices[0].size() + choices[1].size() == n) {
        vector<int> A, B;
        getSumList(dice, A, choices[0]);
        getSumList(dice, B, choices[1]);

        sort(A.begin(), A.end());

        int win = 0;
        for (int i = 0; i < B.size(); i++) {
            int big = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
            win += A.size() - big;
        }

        if (maxChoice.first < win)
            maxChoice = { win, choices[0] };

    } else {
        if (choices[0].size() < half) {
            choices[0].push_back(curr);
            dfs(dice, curr + 1, choices);
            choices[0].pop_back();
        }

        if (choices[1].size() < half) {
            choices[1].push_back(curr);
            dfs(dice, curr + 1, choices);
            choices[1].pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    n = (int)dice.size();
    half = n / 2;

    vector<int> choices[2];
    dfs(dice, 0, choices);

    for (int i = 0; i < maxChoice.second.size(); i++)
        maxChoice.second[i]++;

    return maxChoice.second;
}