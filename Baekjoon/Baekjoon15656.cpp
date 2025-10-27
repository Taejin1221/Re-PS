// Baekjoon15656.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;

void solve() {
    if (ans.size() == m) {
        for (int& a : ans)
            cout << a << ' ';
        cout << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            ans.push_back(arr[i]);
            solve();
            ans.pop_back();
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    solve();

    return 0;
}
