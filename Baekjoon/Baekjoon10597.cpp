// Baekjoon10597.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int n;
string str;
bool visited[51];
vector<int> ans;

bool solve(int idx) {
    if (idx == str.size()) {
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                return false;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';

        return true;
    }

    vector<int> candidate;
    candidate.push_back(str[idx] - '0');
    if (idx < str.size() - 1) {
        candidate.push_back((str[idx] - '0') * 10 + (str[idx + 1] - '0'));
    }

    for (int curr : candidate) {
        int next = idx + 1;
        if (curr >= 10)
            next++;

        if (curr <= n && !visited[curr]) {
            visited[curr] = true;
            ans.push_back(curr);
            if (solve(next))
                return true;
            visited[curr] = false;
            ans.pop_back();
        }
    }

    return false;
}

int main(void) {
    cin >> str;
    int sum = 0;
    for (n = 1; n <= 51 && sum < str.size(); n++)
        sum += 1 + (n >= 10 ? 1 : 0);
    n--;

    solve(0);

    return 0;
}
