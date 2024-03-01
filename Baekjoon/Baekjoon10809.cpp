// Baekjoon10809.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int position[26];
    for (int i = 0; i < 26; i++)
        position[i] = -1;

    for (int i = 0; i < str.size(); i++) {
        char& c = str[i];
        if (position[c - 'a'] == -1)
            position[c - 'a'] = i;
    }

    for (int i = 0; i < 26; i++)
        cout << position[i] << ' ';
    cout << '\n';

    return 0;
}