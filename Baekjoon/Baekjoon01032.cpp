// Baekjoon01032.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string str[50];
    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < str[0].size(); i++) {
        bool isSame = true;
        for (int j = 1; j < n; j++)
            if (str[0][i] != str[j][i]) {
                isSame = false;
                break;
            }

        cout << (isSame ? str[0][i] : '?');
    }

    return 0;
}