// Baekjoon15312.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

const int STROKE[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void) {
    string a, b;
    cin >> a >> b;

    vector<int> ans;
    for (int i = 0; i < a.size(); i++) {
        ans.push_back(STROKE[a[i] - 'A']);
        ans.push_back(STROKE[b[i] - 'A']);
    }

    while (ans.size() > 2) {
        vector<int> temp;
        for (int i = 0; i < ans.size() - 1; i++)
            temp.push_back((ans[i] + ans[i + 1]) % 10);
        ans = temp;
    }

    cout << ans[0] << ans[1] << '\n';

    return 0;
}
