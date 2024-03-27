// Baekjoon02108.cpp
#include <iostream>

#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 8'001
#define IDX(x) ((x) + 4'000)

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    double sum = 0.0;
    int maxFre = 0, frequency[MAX] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];

        frequency[IDX(arr[i])]++;
        maxFre = max(maxFre, frequency[IDX(arr[i])]);
    }
    sort(arr.begin(), arr.end());

    cout << (int)round(sum / n) << '\n';
    cout << arr[n / 2] << '\n';
    vector<int> maxFrequencies;
    for (int i = 0; i < MAX; i++)
        if (frequency[i] == maxFre)
            maxFrequencies.push_back(i - 4'000);
    cout << (maxFrequencies.size() == 1 ? maxFrequencies[0] : maxFrequencies[1]) << '\n';
    cout << arr[n - 1] - arr[0] << '\n';

    return 0;
}