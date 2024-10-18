// Baekjoon02083.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string name;
    int age, weight;

    cin >> name >> age >> weight;

    while (!(name == "#" && age == 0 && weight == 0)) {
        cout << name << ' ';
        if (age > 17 || weight >= 80)
            cout << "Senior";
        else
            cout << "Junior";
        cout << '\n';

        cin >> name >> age >> weight;
    }

    return 0;
}