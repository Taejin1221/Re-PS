#include <iostream>

#include <string>

using namespace std;

int main() {
    string arr[8] = {
        "000",
        "001",
        "010",
        "011",
        "100",
        "101",
        "110",
        "111"
    };

    string n;
    cin >> n;
    if (n[0] <= '1')
        cout << arr[n[0] - '0'][2];
    else if (n[0] <= '3')
        cout << arr[n[0] - '0'][1] << arr[n[0] - '0'][2];
    else
        cout << arr[n[0] - '0'];
    for (int i = 1; i < n.size(); i++)
        cout << arr[n[i] - '0'];
    cout << '\n';

    return 0;
}
