// Baekjoon04921.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string pieces;
    cin >> pieces;

    int time = 1;
    while (pieces != "0") {
        int n = pieces.size();

        bool isValid = true;
        if (pieces[0] != '1' || pieces[n - 1] != '2')
            isValid = false;
        else {
            for (int i = 1; i < pieces.size() && isValid; i++) {
                char me = pieces[i], prev = pieces[i - 1];
                if (me == '2' || me == '3') {
                    if (!(prev == '4' || prev == '6'))
                        isValid = false;
                } else if (me == '4' || me == '5') {
                    if (!(prev == '1' || prev == '3'))
                        isValid = false;
                } else if (me == '6' || me == '7') {
                    if (!(prev == '8'))
                        isValid = false;
                } else if (me == '8') {
                    if (!(prev == '5' || prev == '7'))
                        isValid = false;
                } else
                    isValid = false;
            }
        }
        cout << time << ". " << (isValid ? "VALID" : "NOT") << '\n';

        cin >> pieces;
        time++;
    }

    return 0;
}
