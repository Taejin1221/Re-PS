#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    if (n % 3 == 1)
        cout << 'U';
    else if (n % 3 == 2)
        cout << 'O';
    else
        cout << 'S';
    cout << '\n';
    
    return 0;
}