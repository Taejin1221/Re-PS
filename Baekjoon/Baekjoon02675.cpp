// Baekjoon02675.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;

        string str;
        cin >> str;

        for (char& c : str)
            for (int i = 0; i < r; i++)
                cout << c;
        cout << '\n';
    }

    return 0;
}