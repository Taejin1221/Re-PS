#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while (n != 0) {
        int ans = 0;

        vector<string> record[500];
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;

            double hDouble;
            cin >> hDouble;

            int height = (int)(hDouble * 100.0);
            record[height].push_back(name);

            ans = max(ans, height);
         }

        for (string& name : record[ans])
            cout << name << ' ';
        cout << '\n';

        cin >> n;
    }

    return 0;
}
