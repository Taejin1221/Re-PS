// Baekjoon02798.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] <= m)
                    result = max(result, arr[i] + arr[j] + arr[k]);
            }
        }
    }

    cout << result << '\n';

    return 0;
}