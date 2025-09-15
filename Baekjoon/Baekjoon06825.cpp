// Baekjoon06825.cpp
#include <iostream>

using namespace std;

int main(void) {
    double weight, height;
    cin >> weight >> height;

    double bmi = weight / (height * height);
    if (bmi > 25.0)
        cout << "Overweight";
    else if (18.5 <= bmi && bmi <= 25.0)
        cout << "Normal weight";
    else
        cout << "Underweight";
    cout << '\n';

    return 0;
}
