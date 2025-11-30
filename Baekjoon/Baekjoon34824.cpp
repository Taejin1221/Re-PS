// Baekjoon34824.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    bool isYonsei = false;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if (temp == "korea")
            break;
        else if (temp == "yonsei") {
            isYonsei = true;
            break;
        }
    }

    cout << (isYonsei ? "Yonsei Won!" : "Yonsei Lost...") << '\n';

    return 0;
}
