#include <iostream>

#include <string>

using namespace std;

string getFirst(string curr) {
    if (curr.size() % 2)
        return curr;
    else {
        string prev = "";
        for (int i = 0; i < curr.size(); i += 2)
            for (int j = 0; j < (curr[i] - '0'); j++)
                prev.push_back(curr[i + 1]);

        string prevNext = "";
        for (int i = 0; i < prev.size();) {
            int cnt = 0;
            for (int j = i; j < prev.size() && prev[i] == prev[j]; cnt++, j++);

            prevNext.push_back(cnt + '0');
            prevNext.push_back(prev[i]);
            i += cnt;
        }

        if (prev == curr || prevNext != curr)
            return curr;
        else
            return getFirst(prev);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    for (int t = 1; str != "0"; t++) {
        cout << "Test " << t << ": " << getFirst(str) << '\n';

        cin >> str;
    }

    return 0;
}
