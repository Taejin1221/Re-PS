#include <iostream>

using namespace std;

int main() {
    string binary;
    cin >> binary;

    string ans;
    for (int i = binary.size() - 1; i >= 0; i -= 3) {
        int result = binary[i] - '0';
        if (i - 1 >= 0)
            result += (binary[i - 1] - '0') * 2;
        if (i - 2 >= 0)
            result += (binary[i - 2] - '0') * 4;
        ans.push_back(result + '0');
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << '\n';

    return 0;
}
