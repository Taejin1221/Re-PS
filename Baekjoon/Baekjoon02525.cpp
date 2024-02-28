// Baekjoon02525.cpp
#include <iostream>

using namespace std;

int main(void) {
    int hour, minute, plus;
    cin >> hour >> minute >> plus;

    int hourPlus = plus / 60, minutePlus = plus % 60;

    hour += hourPlus;
    minute += minutePlus;
    if (minute >= 60) {
        hour++;
        minute -= 60;
    }

    if (hour >= 24)
        hour -= 24;

    cout << hour << ' ' << minute << '\n';

    return 0;
}