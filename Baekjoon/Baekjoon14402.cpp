#include <iostream>

#include <map>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    int ans = 0;
    map<string, int> record;
    while (t--) {
        string name;
        char sign;
        cin >> name >> sign;

        auto iter = record.find(name);
        if (sign == '+') {
            if (iter == record.end())
                record.insert({ name, 1 });
            else
                iter->second++;
        } else {
            if (iter == record.end() || iter->second == 0)
                ans++;
            else
                iter->second--;
        }
    }

    for (auto iter = record.begin(); iter != record.end(); ++iter)
        ans += iter->second;

    cout << ans << '\n';

    return 0;
}
