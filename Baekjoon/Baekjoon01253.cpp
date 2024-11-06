// Baekjoon01253.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // n이 2개 이하면 자기 자신을 제외한 다른 수는 1개 또는 0개이기 때문에 당연히 0이다.
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }

    int arr[2'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 모든 두 수의 합을 구한다.
    int zero = 0;
    vector<int> sum;
    for (int i = 0; i < n; i++) {
        // 자기 자신이 0인 경우에는 이진탐색이 아닌 다른 방법으로 체크하기 때문에 제외해준다.
        if (arr[i] == 0) {
            zero++;
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j] == 0)
                continue;

            sum.push_back(arr[i] + arr[j]);
        }
    }
    sort(arr, arr + n);
    sort(sum.begin(), sum.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // 만약 0이 존재하고
        if (zero) {
            // 이번에 체크할 숫자가 0이라면
            if (arr[i] == 0) {
                // 0이 3개 이상이어야 나를 제외한 다른 두 수로 0을 만들 수 있다.
                if (zero >= 3) {
                    ans++;
                    continue;
                }
            } else {
                // 0이 존재한다면 나를 만들기 위해서는 나와 같은 수가 있어야한다.
                // 그렇기 때문에 정렬된 배열에서 앞, 뒤를 체크해주어 같은 숫자가 있는지 판단한다.
                if ((i + 1 < n && arr[i] == arr[i + 1]) || (i - 1 >= 0 && arr[i] == arr[i - 1])) {
                    ans++;
                    continue;
                }
            }
        }
        // 위의 경우가 아니라면 이진탐색으로 찾는다.
        int idx = lower_bound(sum.begin(), sum.end(), arr[i]) - sum.begin();

        if (idx < sum.size() && sum[idx] == arr[i])
            ans++;
    }

    cout << ans << '\n';

    return 0;
}