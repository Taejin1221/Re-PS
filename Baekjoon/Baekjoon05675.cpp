#include <iostream>

#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;
    while (getline(cin, str)) {
        int n = stoi(str);

        cout << (n % 6 == 0? "Y" : "N") << '\n';
    }

    return 0;
}
