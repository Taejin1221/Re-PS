// Baekjoon14038.cpp
#include <iostream>

using namespace std;

int main(void) {
    int win = 0;
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        
        if (c == 'W')
            win++;
    }
    
    if (win >= 5)
        cout << 1;
    else if (win >= 3)
        cout << 2;
    else if (win >= 1)
        cout << 3;
    else
        cout << -1;
    cout << '\n';
    
    return 0;
}
