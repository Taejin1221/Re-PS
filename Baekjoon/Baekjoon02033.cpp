#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    int exp = 0;
    while (n > 10) {
        if (n % 10 >= 5)
            n += 10;
        n /= 10;
        exp++;
    }

    for (int i = 0; i < exp; i++)
        n *= 10;
    cout << n << '\n';

    return 0;
}
