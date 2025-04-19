#include <iostream>

#define MAX 10'000'001
#define MOD 1'000'000'007LL

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll jjin[MAX] = { 0, 4, };
    for (int i = 2; i < MAX; i++) {
        jjin[i] = (jjin[i - 1] * 5) % MOD;
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        if (n == 1)
            cout << 5;
        else
            cout << jjin[n];
        cout << '\n';
    }

    return 0;
}
