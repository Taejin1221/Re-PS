#include <iostream>

#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    bool ans = false;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if (temp == "anj")
            ans = true;
    }

    cout << "뭐야";
    cout << (ans ? ';' : '?') << '\n';

    return 0;
}
