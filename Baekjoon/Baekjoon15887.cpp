// Baekjoon15887.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[1'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pii> ans;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;

                ans.push_back({ j + 1, j + 2 });
            }
        }
    }

    cout << ans.size() << '\n';
    for (pii& a : ans)
        cout << a.first << ' ' << a.second << '\n';

    return 0;
}