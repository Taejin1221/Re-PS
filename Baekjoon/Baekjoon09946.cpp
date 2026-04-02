#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string from, to;
    cin >> from >> to;
    for (int i = 1; !(from == "END" && to == "END"); i++) {
        sort(from.begin(), from.end());
        sort(to.begin(), to.end());

        cout << "Case " << i << ": ";
        if (from == to)
            cout << "same";
        else
            cout << "different";
        cout << '\n';

        cin >> from >> to;
    }

    return 0;
}
