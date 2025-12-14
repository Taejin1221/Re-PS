#include <iostream>

#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'J')
            cout << 'O';
        else if (str[i] == 'O')
            cout << 'I';
        else
            cout << 'J';
    }
    cout << '\n';

    return 0;
}
