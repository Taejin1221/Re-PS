// Baekjoon15663.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, m, arr[8];
vector<vector<int>> ans;

void dfs(vector<int>& currList, bool visited[]) {
    if (currList.size() == m) {
        for (vector<int>& a : ans) {
            bool isSame = true;
            for (int i = 0; i < currList.size(); i++) {
                if (a[i] != currList[i]) {
                    isSame = false;
                    break;
                }
            }

            if (isSame)
                return;
        }

        ans.push_back(currList);
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                currList.push_back(arr[i]);
                dfs(currList, visited);
                currList.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    vector<int> currList;
    bool visited[8] = { false, };
    dfs(currList, visited);

    for (vector<int>& a : ans) {
        for (int& i : a)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}