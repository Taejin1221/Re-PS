// Baekjoon21315.cpp
#include <iostream>

#include <deque>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& source, int k) {
    int n = source.size();

    vector<deque<int>> arr (k + 2);
    for (int i = n - 1; i >= 0; i--)
        arr[0].push_back(source[i]);

    for (int i = 1; i <= k + 1; i++) {
        int num = 1 << (k - i + 1);
        for (int j = 0; j < num; j++) {
            arr[i].push_back(arr[i - 1].front());
            arr[i - 1].pop_front();
        }
    }

    vector<int> result;
    for (int i = k + 1; i >= 0; i--) {
        while (!arr[i].empty()) {
            result.push_back(arr[i].back());
            arr[i].pop_back();
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int target[1'000];
    for (int i = 0; i < n; i++)
        cin >> target[i];

    vector<int> start;
    for (int i = 1; i <= n; i++)
        start.push_back(i);

    int ans[2] = { -1, -1 };
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            // 2^k가 n보다 큰 경우
            if ((1 << i) >= n || (1 << j) >= n)
                continue;

            vector<int> first = shuffle(start, i);
            vector<int> second = shuffle(first, j);

            bool find = true;
            for (int k = 0; k < n; k++) {
                if (target[k] != second[k]) {
                    find = false;
                    break;
                }
            }

            if (find) {
                ans[0] = i, ans[1] = j;
                break;
            }
        }

        if (!(ans[0] == -1 && ans[1] == -1))
            break;
    }

    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}
