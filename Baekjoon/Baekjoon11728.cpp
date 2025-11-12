// Baekjoon11728.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    int n = a + b;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}
