#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int temp1, temp2, temp3;
    cin >> temp1 >> temp2 >> temp3;
    int score1 = temp1 + temp2 * 2 + temp3 * 3;

    cin >> temp1 >> temp2 >> temp3;
    int score2 = temp1 + temp2 * 2 + temp3 * 3;

    if (score1 > score2)
        cout << 1;
    else if (score1 < score2)
        cout << 2;
    else
        cout << 0;
    cout << '\n';

    return 0;
}
