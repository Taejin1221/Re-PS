// Baekjoon02447.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

using pii = pair<int, int>;

void solve(vector<string>& ans, int size, pii start) {
    int row = start.first, col = start.second;
    if (size == 3) {
        ans[row][col] = ans[row][col + 1] = ans[row][col + 2] = '*';
        ans[row + 1][col] = '*'; ans[row + 1][col + 1] = ' '; ans[row + 1][col + 2] = '*';
        ans[row + 2][col] = ans[row + 2][col + 1] = ans[row + 2][col + 2] = '*';
    } else {
        int third = size / 3;
        solve(ans, third, start);
        solve(ans, third, { row, col + third });
        solve(ans, third, { row, col + third * 2 });

        solve(ans, third, { row + third, col});
        solve(ans, third, { row + third, col + third * 2});

        solve(ans, third, { row + third * 2, col});
        solve(ans, third, { row + third * 2, col + third});
        solve(ans, third, { row + third * 2, col + third * 2});
    }
}

int main(void) {
    int n;
    cin >> n;

    vector<string> ans(n, string(n, ' '));
    solve(ans, n, { 0, 0 });

    for (string& s : ans)
        cout << s << '\n';
    
    return 0;
}