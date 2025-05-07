// Baekjoon26084.cpp
#include <iostream>

#include <string>

using namespace std;

using ll = long long;

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string target;
    cin >> target;

    int targetNum[26] = { 0, };
    for (int i = 0; i < target.size(); i++)
        targetNum[target[i] - 'A']++;

    int n;
    cin >> n;

    ll candidate[26] = { 0LL, };
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        candidate[temp[0] - 'A']++;
    }

    ll ans = 1LL;
    for (int i = 0; i < 26; i++) {
        if (targetNum[i] == 1)
            ans = ans * candidate[i];
        else if (targetNum[i] == 2)
            ans = ans * max(candidate[i] * (candidate[i] - 1) / 2, 0LL);
        else if (targetNum[i] == 3)
            ans = ans * max(candidate[i] * (candidate[i] - 1) * (candidate[i] - 2) / 6, 0LL);
    }

    cout << ans << '\n';

    return 0;

}