// Baekjoon15654.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<bool> visited;

void solve(vector<int>& currArr) {
    if (currArr.size() == m) {
        for (int& ca : currArr)
            cout << ca << ' ';
        cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            currArr.push_back(arr[i]);
            solve(currArr);
            currArr.pop_back();
            visited[i] = false;
        }
    }
}

int main(void) {
    cin >> n >> m;

    arr = vector<int> (n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    visited = vector<bool> (n);
    vector<int> result;
    solve(result);

    return 0;
}