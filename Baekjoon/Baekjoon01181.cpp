// Baekjoon01181.cpp
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b) {
    return (a.size() == b.size()) ? a.compare(b) < 0 : a.size() < b.size();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), compare);

    cout << arr[0] << '\n';
    for (int i = 1; i < n; i++)
        if (arr[i] != arr[i - 1])
            cout << arr[i] << '\n';

    return 0;
}