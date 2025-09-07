#include <iostream>

#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int ans[26] = { 0, };
    for (int i = 0; i < str.size(); i++) {
        ans[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
