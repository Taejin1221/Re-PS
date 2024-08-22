// Baekjoon01759.cpp
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, l;
char arr[15];
bool visited[32'768];
vector<string> ans;

void solve(string& str, int idx, int vowel, int consonant, int currVisited) {
    if (str.size() == l && vowel >= 1 && consonant >= 2 && !visited[currVisited]) {
        visited[currVisited] = true;
        ans.push_back(str);
    } else {
        if (idx == n)
            return;

        str.push_back(arr[idx]);
        int nextVisited = currVisited | (1 << idx);
        if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u')
            solve(str, idx + 1, vowel + 1, consonant, nextVisited);
        else
            solve(str, idx + 1, vowel, consonant + 1, nextVisited);
        str.pop_back();

        solve(str, idx + 1, vowel, consonant, currVisited);
    }
}

int main(void) {
    cin >> l >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    string str;
    solve(str, 0, 0, 0, 0);

    for (string& a : ans)
        cout << a << '\n';

    return 0;
}