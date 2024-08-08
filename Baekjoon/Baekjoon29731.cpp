// Baekjoon29731.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string promise[7] = {
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "Never gonna stop"
    };

    int n;
    cin >> n;
    getchar();

    bool allPromise = true;
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        bool isHacked = true;
        for (int j = 0; j < 7; j++) {
            if (promise[j] == str) {
                isHacked = false;
                break;
            }
        }

        if (isHacked)
            allPromise = false;
    }

    cout << (allPromise ? "No" : "Yes") << '\n';

    return 0;
}