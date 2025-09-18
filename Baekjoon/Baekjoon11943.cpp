#include <iostream>

using namespace std;

int main() {
    int a1, a2, o1, o2;
    cin >> a1 >> o1 >> a2 >> o2;

    cout << min(a1 + o2, a2 + o1) << '\n';

    return 0;
}
