// Baekjoon14369.cpp
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

int alphabet[128];

string info[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

bool dfs(string& ans) {
    bool isAns = true;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (alphabet[i] != 0) {
            isAns = false;
            break;
        }
    }

    if (isAns)
        return true;

    for (int i = 0; i < 10; i++) {
        bool flag = true;
        for (int j = 0; j < info[i].size(); j++)
            flag &= alphabet[info[i][j]] > 0;

        if (i == 3 || i == 7)
            flag &= alphabet['E'] >= 2;
        else if (i == 9)
            flag &= alphabet['N'] >= 2;

        if (flag) {
            ans.push_back(i + '0');
            for (int j = 0; j < info[i].size(); j++)
                alphabet[info[i][j]]--;

            if (dfs(ans))
                return true;

            ans.pop_back();
            for (int j = 0; j < info[i].size(); j++)
                alphabet[info[i][j]]++;
        }
    }

    return false;
}

void solve() {
    fill(alphabet, alphabet + 128, 0);

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
        alphabet[str[i]]++;

    string ans;
    dfs(ans);

    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
