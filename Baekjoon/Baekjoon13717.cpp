// Baekjoon13717.cpp
#include <iostream>

#include <string>

using namespace std;

using psi = pair<string, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    int sum = 0;
    psi ans = { "", -1 };
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        int k, m;
        cin >> k >> m;

        int evol = 0;
        while (m >= k) {
            m -= k;
            evol++;
            m += 2;
        }

        sum += evol;
        if (ans.second < evol)
            ans = { name, evol };
    }

    cout << sum << '\n';
    cout << ans.first << '\n';

    return 0;
}
