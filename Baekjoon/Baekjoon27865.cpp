// Baekjoon27865.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < 20000; i++) {
        cout << "? " << 1 << '\n' << flush;

        char a;
        cin >> a;

        if (a == 'Y')
            break;
    }

    cout << "! " << 1 << flush;

    return 0;
}