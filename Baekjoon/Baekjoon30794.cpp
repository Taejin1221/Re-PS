#include <iostream>

#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans;
    cin >> ans;

    string str;
    cin >> str;

    if (str == "miss")
        ans *= 0;
    else if (str == "bad")
        ans *= 200;
    else if (str == "cool")
        ans *= 400;
    else if (str == "great")
        ans *= 600;
    else
        ans *= 1000;
    cout << ans << '\n';  

    return 0;
}
