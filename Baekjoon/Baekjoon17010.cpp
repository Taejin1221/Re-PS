// Baekjoon17010.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        char c;
        cin >> c;

        for (int i = 0; i < n; i++)
            cout << c;
        cout << '\n';
    }

    return 0;
}
