// Baekjoon15652.cpp
#include <iostream>

#include <vector>

using namespace std;

int n, m;

void solve(vector<vector<int>>& ans, int curr, vector<int>& currArr) {
    if (currArr.size() == m)
        ans.push_back(currArr);
    else {
        for (int i = curr; i <= n; i++) {
            currArr.push_back(i);
            solve(ans, i, currArr);
            currArr.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> n >> m;

    vector<vector<int>> ans;
    vector<int> currArr;

    solve(ans, 1, currArr);

    for (vector<int>& a : ans) {
        for (int& b : a)
            cout << b << ' ';
        cout << '\n';
    }

    return 0;
}