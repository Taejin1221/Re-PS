// Bakjoon06810.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str = "9780921418";
    for (int i = 0; i < 3; i++) {
        char last;
        cin >> last;

        str.push_back(last);
    }

    int ans = 0;
    for (int i = 0; i < str.size(); i++)
        ans += (str[i] - '0') * (i % 2 == 0 ? 1 : 3);

    cout << "The 1-3-sum is " << ans << '\n';

    return 0;
}
