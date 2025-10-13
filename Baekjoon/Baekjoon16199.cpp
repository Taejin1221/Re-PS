// Baekjoon16199.cpp
#include <iostream>

using namespace std;

int main(void) {
    int by, bm, bd; // birth year month day
    cin >> by >> bm >>  bd;

    int ty, tm, td; // today year month day
    cin >> ty >> tm >> td;

    int age = ty - by;
    if (tm < bm || (tm == bm && td < bd))
        age--;
    cout << age << '\n';

    age = ty - by + 1;
    cout << age << '\n';

    cout << (age - 1) << '\n';

    return 0;
}
