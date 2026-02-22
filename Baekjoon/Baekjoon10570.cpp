// Baekjoon10570.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        int record[1'001] = { 0, };
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            record[temp]++;

            if (record[ans] < record[temp])
                ans = temp;
            else if (record[ans] == record[temp])
                ans = min(ans, temp);
        }

        cout << ans << '\n';
    }

    return 0;
}