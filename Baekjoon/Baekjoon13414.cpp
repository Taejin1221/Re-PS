// Baekjoon13414.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> k >> n;

    string arr[500];
    map<string, int> table;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (table.find(arr[i]) == table.end())
            table.insert({ arr[i], i });
        else
            table.find(arr[i])->second = i;
    }

    int ans = 0;
    for (int i = 0; i < n && ans < k; i++) {
        if (table.find(arr[i])->second == i) {
            cout << arr[i] << '\n';
            ans++;
        }
    }

    return 0;
}
