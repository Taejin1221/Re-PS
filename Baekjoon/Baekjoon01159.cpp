// Baekjoon01159.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int first[26] = { false, };
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        first[name[0] - 'a']++;
    }

    bool withdraw = true;
    for (int i = 0; i < 26; i++) {
        if (first[i] >= 5) {
            withdraw = false;
            cout << ((char)('a' + i));
        }
    }
    if (withdraw)
        cout << "PREDAJA";
    cout << '\n';

    return 0;
}