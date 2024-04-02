// Baekjoon15649.cpp
#include <iostream>

#include <vector>

using namespace std;

int n, m;

void solve(vector<vector<int>>& ans, vector<int>& currArr, vector<bool>& visited) {
    if (currArr.size() == m)
        ans.push_back(currArr);
    else {
        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;
            currArr.push_back(i);
            visited[i] = true;
            solve(ans, currArr, visited);
            currArr.pop_back();
            visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> n >> m;

    vector<vector<int>> ans;
    vector<int> currArr;
    vector<bool> visited(n, false);

    solve(ans, currArr, visited);

    for (vector<int>& a : ans) {
        for (int& b : a)
            cout << b << ' ';
        cout << '\n';
    }

    return 0;
}