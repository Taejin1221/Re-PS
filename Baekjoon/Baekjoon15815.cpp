#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int ans = 0;
    vector<int> stck;
    for (char& c : str) {
        if ('0' <= c && c <= '9')
            stck.push_back(c - '0');
        else {
            int opr2 = stck.back(); stck.pop_back();
            int opr1 = stck.back(); stck.pop_back();

            int result;
            if (c == '+')
                result = opr1 + opr2;
            else if (c == '-')
                result = opr1 - opr2;
            else if (c == '*')
                result = opr1 * opr2;
            else
                result = opr1 / opr2;

            stck.push_back(result);
        }
    }

    cout << stck.back() << '\n';

    return 0;
}
