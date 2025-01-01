// Baekjoon25372.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    while (n--) {
        string password;
        cin >> password;

        int size = password.size();
        if (6 <= size && size <= 9)
            cout << "yes";
        else
            cout << "no";
        cout << '\n';
    }

    return 0;
}
