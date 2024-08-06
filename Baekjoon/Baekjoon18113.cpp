// Baekjoon18113.cpp
#include <iostream>

#include <vector>

using namespace std;

int check(vector<int>& 김밥s, int p) {
    int result = 0;
    for (int& 김밥 : 김밥s) {
        result += 김밥 / p;
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> 김밥s;
    for (int i = 0; i < n; i++) {
        int 김밥;
        cin >> 김밥;

        if (김밥 >= 2 * k)
            김밥s.push_back(김밥 - 2 * k);
        else if (김밥 >= k)
            김밥s.push_back(김밥 - k);
    }

    int left = 0, right = 1'000'000'001;
    while (left + 1 < right) {
        int mid = (left + right) / 2;

        if (check(김밥s, mid) >= m)
            left = mid;
        else
            right = mid;
    }

    if (left == 0)
        cout << -1;
    else
        cout << left;
    cout << '\n';

    return 0;
}