// Baekjoon30445.cpp
#include <iostream>

using namespace std;

int main(void) {
    string str;
    getline(cin, str);

    int ph = 0, pg = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'H' || str[i] == 'A' || str[i] == 'P' || str[i] == 'Y')
            ph++;

        if (str[i] == 'S' || str[i] == 'A' || str[i] == 'D')
            pg++;
    }

    int ans;
    if (ph == 0 && pg == 0)
        cout << "50.00";
    else {
        ans = ph * 100000 / (ph + pg);
        if (ans % 10 >= 5)
            ans += 10;
        ans /= 10;
        cout << ans / 100 << '.';
        if (ans % 100 == 0)
            cout << "00";
        else if (ans % 100 < 10)
            cout << '0' << ans % 100;
        else
            cout << ans % 100;
    }

    cout << '\n';

    return 0;
}
