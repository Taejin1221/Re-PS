// Baekjoon21314.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int n = str.size();

    int idx = 0, digit = 0;
    while (idx < n) {
        while (idx < n && str[idx] != 'K')
            idx++, digit++;

        if (idx < n) {
            cout << '5';
            idx++;
            for (int i = 0; i < digit; i++)
                cout << '0';
            digit = 0;
        }
    }

    for (int i = 0; i < digit; i++)
        cout << '1';
    cout << '\n';


    idx = 0, digit = 0;
    while (idx < n) {
        while (idx < n && str[idx] != 'K')
            idx++, digit++;

        if (idx < n) {
            if (digit >= 1) {
                cout << '1';
                for (int i = 1; i < digit; i++)
                    cout << '0';
                digit = 0;
            }

            cout << '5';
            idx++;
        }
    }

    if (digit != 0) {
        cout << '1';
        for (int i = 1; i < digit; i++)
            cout << '0';
    }
    cout << '\n';

    return 0;
}
