// Baekjoon11367.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        string name;
        cin >> name;
        cout << name << ' ';

        int score;
        cin >> score;

        if (score >= 97)
            cout << "A+";
        else if (score >= 90)
            cout << "A";
        else if (score >= 87)
            cout << "B+";
        else if (score >= 80)
            cout << "B";
        else if (score >= 77)
            cout << "C+";
        else if (score >= 70)
            cout << "C";
        else if (score >= 67)
            cout << "D+";
        else if (score >= 60)
            cout << "D";
        else
            cout << "F";
        cout << '\n';
    }

    return 0;
}
