// Baekjoon08958.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int result = 0, prev = 0;
        for (char& c : str) {
            if (c == 'O')
                result += ++prev;
            else
                prev = 0;
        }

        cout << result << '\n';
    }

    return 0;
}