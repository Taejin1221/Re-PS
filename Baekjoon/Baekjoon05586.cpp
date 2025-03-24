// Baekjoon05586.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int joi = 0, ioi = 0;
    for (int i = 2; i < str.size(); i++) {
        if (str[i - 1] == 'O' && str[i] == 'I') {
            if (str[i - 2] == 'I')
                ioi++;
            else if (str[i - 2] == 'J')
                joi++;
        }
    }

    cout << joi << '\n' << ioi << '\n';

    return 0;
}
