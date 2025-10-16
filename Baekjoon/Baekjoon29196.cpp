#include <iostream>

#include <string>

using namespace std;

int main() {
    string k;
    cin >> k;

    cout << "YES\n";

    int start;
    for (start = 2; start < k.size() && k[start] == '0'; start++);
    for (int i = start; i < k.size(); i++)
        cout << k[i];

    cout << ' ';

    cout << 1;
    for (int i = 0; i < (k.size() - 2); i++)
        cout << 0;
    cout << '\n';

    return 0;
}
