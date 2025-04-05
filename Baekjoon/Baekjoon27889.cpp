// Baekjoon27889.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string abb;
    cin >> abb;

    if (abb == "NLCS")
        cout << "North London Collegiate School";
    else if (abb == "BHA")
        cout << "Branksome Hall Asia";
    else if (abb == "KIS")
        cout << "Korea International School";
    else
        cout << "St. Johnsbury Academy";
    cout << '\n';

    return 0;
}
