#include <iostream>

#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        int n = str.size();
        for (int j = 1; j <= n; j++) {
            if (j == n || str[j - 1] != str[j])
                cout << str[j - 1];
        }
        cout << '\n';
    }

    return 0;
}
