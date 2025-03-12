#include <iostream>

using namespace std;

int main(void) {
    int day;
    cin >> day;
    
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int car;
        cin >> car;

        ans += (car == day);
    }
    
    cout << ans << '\n';
    
    return 0;
}
