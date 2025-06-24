// Baekjoon05524.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if ('A' <= str[j] && str[j] <= 'Z')
                cout << ((char)(str[j] + 32));
            else
                cout << str[j];
        }
        cout << '\n';
    }

    return 0;
}
