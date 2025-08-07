#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n) {
        cout << n << ' ';
        int result = n;
        while (result >= 10) {
            n = result;
            result = 1;
            while (n) {
                result *= (n % 10);
                n /= 10;
            }
            cout << result << ' ';
        }
        cout << '\n';
        
        cin >> n;
    }

    return 0;
}
