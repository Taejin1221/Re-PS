#include <iostream>

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    if (h < 2)
        cout << "Before";
    else if (h > 2)
        cout << "After";
    else {
        if (m < 18)
           cout << "Before";
        else if (m > 18)
            cout << "After";
        else
            cout << "Special";
    }

    return 0;
}
