// Baekjoon09204.cpp
#include <iostream>

using namespace std;

using pci = pair<char, int>;
using pii = pair<int, int>;

void solve() {
    pci from, to;
    cin >> from.first >> from.second >> to.first >> to.second;

    pii start = { from.first - 'A', from.second - 1 },
        end = { to.first - 'A', to.second - 1 };

    if ((start.first + start.second) % 2 != (end.first + end.second) % 2)
        cout << "Impossible";
    else {
        pii startDia = { start.first - start.second, start.first + start.second },
            endDia = { end.first - end.second, end.first + end.second };
        if (start.first == end.first && start.second == end.second)
            cout << "0 " << from.first << ' ' << from.second;
        else if ((startDia.first == endDia.first) || (startDia.second == endDia.second)) {
            cout << "1 " << from.first << ' ' << from.second << ' ' << to.first << ' ' << to.second;
        } else {
            bool isFind = false;
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    if ((startDia.first == (row - col) && endDia.second == (row + col))
                        || (startDia.second == (row + col) && endDia.first == (row - col))) {
                        cout << "2 ";
                        cout << from.first << ' ' << from.second << ' ';
                        cout << ((char)(row + 'A')) << ' ' << (col + 1) << ' ';
                        cout << to.first << ' ' << to.second;

                        isFind = true;
                        break;
                    }
                }

                if (isFind)
                    break;
            }
        }
    }
    cout << '\n';
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
