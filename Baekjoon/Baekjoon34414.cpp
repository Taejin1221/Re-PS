#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool ans = true;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp < 48)
            ans = false;
    }

    cout << (ans ? "True" : "False") << '\n';

    return 0;
}
