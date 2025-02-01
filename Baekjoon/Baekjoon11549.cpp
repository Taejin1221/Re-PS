#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    
    int ans = 0, arr[5];
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        if (arr[i] == t)
            ans++;
    }
    
    cout << ans << '\n';
    
    return 0;
}
