#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "11\n";
        cout << "A B C D E F G H J L M\n";
    } else if (n == 2 || n == 3) {
        cout << "9\n";
        cout << "A C E F G H I L M\n";
    } else if (n == 4) {
        cout << "9\n";
        cout << "A B C E F G H L M\n";
    } else {
        cout << "8\n";
        if (n <= 9)
            cout << "A C E F G H L M\n";
        else
            cout << "A B C F G H L M\n";
    }

    return 0;
}
