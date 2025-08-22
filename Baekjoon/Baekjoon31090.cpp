#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int n1 = n + 1;
        if (n1 % (n % 100) == 0)
            cout << "Good";
        else
            cout << "Bye";
        cout << '\n';
    }

    return 0;
}