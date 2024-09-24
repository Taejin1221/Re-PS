// Baekjoon32297.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string str;
    cin >> str;

    bool isGori = false;
    for (int i = 0; i < n - 3; i++) {
        if (str[i] == 'g' && str[i + 1] == 'o' && str[i + 2] == 'r' && str[i + 3] == 'i')
            isGori = true;
    }

    cout << (isGori ? "YES" : "NO") << '\n';

    return 0;
}