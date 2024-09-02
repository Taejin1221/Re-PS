// Baekjoon32158.cpp
#include <iostream>

#include <queue>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    queue<int> Ps, Cs;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'P') {
            if (Cs.empty())
                Ps.push(i);
            else {
                int j = Cs.front(); Cs.pop();

                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        } else if (str[i] == 'C') {
            if (Ps.empty())
                Cs.push(i);
            else {
                int j = Ps.front(); Ps.pop();

                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    cout << str << '\n';

    return 0;
}