// Baekjoon15666.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, curr;
vector<vector<int>> ans;

void solve(int idx) {
    if (curr.size() == m)
        ans.push_back(curr);
    else {
        for (int i = idx; i < arr.size(); i++) {
            curr.push_back(arr[i]);
            solve(i);
            curr.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }
        

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    solve(0);

    for (vector<int>& v : ans) {
        for (int& a : v)
            cout << a << ' ';
        cout << '\n';
    }

    return 0;
}