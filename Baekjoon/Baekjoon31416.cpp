// Baekjoon31416.cpp
#include <iostream>

using namespace std;

int main(void) {
    int q;
    cin >> q;

    while (q--) {
        int ta, tb, va, vb;
        cin >> ta >> tb >> va >> vb;

        bool isDohunB = true;
        int time = 0, dohun = tb, sanghyuk = ta;
        while (!(va == 0 && vb == 0)) {
            dohun--, sanghyuk--;

            if (sanghyuk == 0) {
                if (va > 0)
                    va--;

                if (va > 0)
                    sanghyuk = ta;
            }

            if (dohun == 0) {
                if (isDohunB)
                    vb--;
                else {
                    if (va > 0)
                        va--;
                }

                if (vb == 0) {
                    isDohunB = false;
                    dohun = ta;
                } else
                    dohun = tb;
            }
            time++;
        }

        cout << time << '\n';
    }

    return 0;
}