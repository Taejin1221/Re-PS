// Baekjoon05358.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    while (getline(cin, str)) {
        for (char& c : str) {
            if (c == 'i')
                cout << 'e';
            else if (c == 'e')
                cout << 'i';
            else if (c == 'I')
                cout << 'E';
            else if (c == 'E')
                cout << 'I';
            else
                cout << c;
        }
        cout << '\n';
    }

    return 0;
}
