#include <iostream>

#include <map>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        map<ll, int> record;
        for (int i = 0; i < n; i++) {
            ll temp;
            cin >> temp;

            auto iter = record.find(temp);
            if (iter == record.end())
                record.insert({temp, 1});
            else
                iter->second++;
        }

        ll ans = -1LL;
        for (auto iter = record.begin(); iter != record.end(); ++iter) {
            if (iter->second > n / 2) {
                ans = iter->first;
                break;
            }
        }

        if (ans == -1LL)
            cout << "SYJKGW";
        else
            cout << ans;
        cout << '\n';
    }

    return 0;
}
