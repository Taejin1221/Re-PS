// Baekjoon25206.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    double sumScore = 0.0, sumTime = 0.0;

    for (int i = 0; i < 20; i++) {
        string name, grade;
        double time;

        cin >> name >> time >> grade;
        if (grade != "P")
            sumTime += time;

        if (grade == "A+")
            sumScore += time * 4.5;
        else if (grade == "A0")
            sumScore += time * 4.0;
        else if (grade == "B+")
            sumScore += time * 3.5;
        else if (grade == "B0")
            sumScore += time * 3.0;
        else if (grade == "C+")
            sumScore += time * 2.5;
        else if (grade == "C0")
            sumScore += time * 2.0;
        else if (grade == "D+")
            sumScore += time * 1.5;
        else if (grade == "D0")
            sumScore += time * 1.0; 
    }

    cout << fixed;
    cout.precision(4);
    cout << sumScore / sumTime << '\n';

    return 0;
}