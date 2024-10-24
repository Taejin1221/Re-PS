// Baekjoon02635.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> ans;

    vector<int> temp;
    for (int i = 0; i <= n; i++) {
        temp.push_back(n);
        temp.push_back(i);
        while (temp.back() >= 0) {
            int l = temp.size();
            temp.push_back(temp[l - 2] - temp[l - 1]);
        }
        temp.pop_back();

        if (temp.size() > ans.size())
            ans = temp;
        temp.clear();
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}