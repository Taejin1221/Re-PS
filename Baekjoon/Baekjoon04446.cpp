// Baekjoon04446.cpp
#include <iostream>

#include <string>

using namespace std;

int find(char str[], char target) {
    for (int i = 0; str[i]; i++)
        if (str[i] == target)
            return i;

    return -1;
}

int main(void) {
    char vowel[2][7] = { "aiyeou", "AIYEOU" };
    char conso[2][21] = { "bkxznhdcwgpvjqtsrlmf", "BKXZNHDCWGPVJQTSRLMF" };

    string str;
    while (getline(cin, str)) {
        for (char& c : str) {
            char ans = c;

            int isCapital = 0;
            if ('A' <= c && c <= 'Z')
                isCapital = 1;

            int idx = find(vowel[isCapital], c);
            if (idx != -1)
                ans = vowel[isCapital][(idx + 3) % 6];
            else {
                idx = find(conso[isCapital], c);
                if (idx != -1)
                    ans = conso[isCapital][(idx + 10) % 20];
            }

            cout << ans;
        }

        cout << '\n';
    }

    return 0;
}