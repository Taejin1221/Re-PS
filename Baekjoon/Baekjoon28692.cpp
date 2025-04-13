#include <iostream>

using namespace std;

int main(void) {
    char s;
    cin >> s;
    
    if (s == 'M')
        cout << "MatKor";
    else if (s == 'W')
        cout << "WiCys";
    else if (s == 'C')
        cout << "CyKor";
    else if (s == 'A')
        cout << "AlKor";
    else
        cout << "$clear";
    cout << '\n';
    
    return 0;
}