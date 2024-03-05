// Baekjoon03009.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    pii a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    if (a.first == b.first)
        cout << c.first;
    else if (b.first == c.first)
        cout << a.first;
    else
        cout << b.first;
    
    cout << ' ';

    if (a.second == b.second)
        cout << c.second;
    else if (b.second == c.second)
        cout << a.second;
    else
        cout << b.second;

    cout << '\n';

    return 0;
}