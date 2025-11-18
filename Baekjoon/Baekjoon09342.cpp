// Baekjoon09342.cpp
#include <iostream>

using namespace std;

bool isABCDEFG(char c) {
    return (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F');
}

bool isAFC(char c1, char c2, char c3) {
    return (c1 == 'A' && c2 == 'F' && c3 == 'C');
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        int n = (int)str.size();

        string comp = "";
        comp.push_back(str[0]);
        for (int i = 1; i < n; i++)
            if (str[i - 1] != str[i])
                comp.push_back(str[i]);

        int m = (int)comp.size();

        bool ans = false;
        if (m == 3) {
            if (comp == "AFC")
                ans = true;
        } else if (m == 4) {
            if ((isABCDEFG(comp[0]) && isAFC(comp[1], comp[2], comp[3]))
                || (isAFC(comp[0], comp[1], comp[2]) && isABCDEFG(comp[3])))
                ans = true;
        } else if (m == 5) {
            if (isABCDEFG(comp[0]) && isAFC(comp[1], comp[2], comp[3]) && isABCDEFG(comp[4]))
                ans = true;
        }

        cout << (ans ? "Infected!" : "Good") << '\n';
    }

    return 0;
}
