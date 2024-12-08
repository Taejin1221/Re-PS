// Baekjoon16986.cpp
#include <iostream>

#include <vector>

using namespace std;

int n, k;
int winTable[10][10];
int rsp[3][20]; // 각 플레이어들이 낸 가위/바위/보

const int restTable[3][3] = {
    { -1, 2, 1 },
    { 2, -1, 0 },
    { 1, 0, -1}
};

bool isWin(vector<int>& curr) {
    for (int i = 0; i < curr.size(); i++)
        rsp[0][i] = curr[i];

    int winNum[3] = { 0, };

    int p1 = 0, p2 = 1;
    int idxs[3] = { 0, 0, 0 };
    int size[3] = { (int)curr.size(), 20, 20 };
    while (winNum[0] < k && winNum[1] < k && winNum[2] < k) {
        if (!(idxs[p1] < size[p1] && idxs[p2] < size[p2]))
            break;

        int s1 = rsp[p1][idxs[p1]], s2 = rsp[p2][idxs[p2]];
        idxs[p1]++;
        idxs[p2]++;

        bool isP1Win = true;
        if (winTable[s1][s2] == 2)
            winNum[p1]++;
        else if (winTable[s1][s2] == 0) {
            winNum[p2]++;
            isP1Win = false;
        } else {
            if (p1 < p2) {
                winNum[p2]++;
                isP1Win = false;
            } else
                winNum[p1]++;
        }

        if (isP1Win)
            p2 = restTable[p1][p2];
        else
            p1 = restTable[p1][p2];
    }

    if (winNum[0] == k)
        return true;
    else
        return false;
}

bool solve(vector<int>& curr, bool visited[]) {
    if (curr.size() == n) {
        return isWin(curr);
    } else {
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                curr.push_back(i);
                if (solve(curr, visited))
                    return true;
                curr.pop_back();
                visited[i] = false;
            }
        }

        return false;
    }
}

int main(void) {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> winTable[i][j];
        }
    }

    for (int i = 1; i <= 2; i++)
        for (int j = 0; j < 20; j++)
            cin >> rsp[i][j];

    vector<int> curr;
    bool visited[10] = { false, };
    if (solve(curr, visited))
        cout << 1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}
