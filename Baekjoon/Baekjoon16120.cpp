// Baekjoon16120.cpp
#include <iostream>

#include <vector>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int n = str.size();

    bool isPPAP = true;
    vector<char> stck;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            int stckIdx = stck.size();
            if (
                (stckIdx >= 2 && stck[stckIdx - 1] == 'P' && stck[stckIdx - 2] == 'P') &&
                (i < n - 1 && str[i + 1] == 'P')
            ) {
                stck.pop_back();

                i++;
            } else {
                isPPAP = false;
                break;
            }
        } else
            stck.push_back(str[i]);
    }

    if (isPPAP && stck.size() == 1 && stck.back() == 'P')
        cout << "PPAP";
    else
        cout << "NP";
    cout << '\n';

    return 0;
}
