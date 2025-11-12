// Baekjoon25640.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string target;
    cin >> target;

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if (target == temp)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
