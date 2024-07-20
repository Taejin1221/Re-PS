// Baekjoon03018.cpp
#include <iostream>

using namespace std;

void shareSong(bool source[], bool destination[], int len) {
    for (int i = 0; i < len; i++)
        destination[i] = destination[i] | source[i];
}

bool knowSameSong(bool arr1[], bool arr2[], int len) {
    for (int i = 0; i < len; i++)
        if (!(arr1[i] & arr2[i]))
            return false;

    return true;
}

int main(void) {
    int n, e;
    cin >> n >> e;

    int newSong = 0;
    bool songTable[101][101] = { { false, }, };
    for (int t = 0; t < e; t++) {
        int k;
        cin >> k;

        int camp[101];
        bool noSun = true;
        for (int i = 0; i < k; i++) {
            cin >> camp[i];

            if (camp[i] == 1)
                noSun = false;
        }

        if (noSun) {
            bool songMerge[101] = { false, };
            for (int i = 0; i < k; i++)
                shareSong(songTable[camp[i]], songMerge, newSong);
            
            for (int i = 0; i < k; i++)
                shareSong(songMerge, songTable[camp[i]], newSong);
        } else {
            for (int i = 0; i < k; i++)
                songTable[camp[i]][newSong] = true;
            newSong++;
        }
    }

    for (int i = 1; i <= n; i++)
        if (knowSameSong(songTable[1], songTable[i], newSong))
            cout << i << '\n';

    return 0;
}