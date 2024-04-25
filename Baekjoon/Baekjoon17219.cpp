// Baekjoon17219.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, string> passwords;
    for (int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;

        passwords.insert({ site, pw });
    }

    for (int i = 0; i < m; i++) {
        string site;
        cin >> site;

        cout << passwords.find(site)->second << '\n';
    }

    return 0;
}