// Baekjoon30801.cpp
#include <iostream>

#include <string>

using namespace std;

int getDirection(char s) {
    if (s == '1')
        return 1;
    else if (s == '2' || s == 'S')
        return 2;
    else if (s == '3')
        return 3;
    else if (s == '4' || s == 'A')
        return 4;
    else if (s == '6' || s == 'D')
        return 6;
    else if (s == '7')
        return 7;
    else if (s == '8' || s == 'W')
        return 8;
    else if (s == '9')
        return 9;
    else
        return 0;
}

int main(void) {
    string note;
    cin >> note;

    int arr[12];

    int noteIdx, arrIdx;
    for (noteIdx = 0, arrIdx = 0; noteIdx < note.size(); arrIdx++) {
        int& currNote = arr[arrIdx];
        if (note[noteIdx] == 'W') currNote = 8;
        else if (note[noteIdx] == 'A') currNote = 4;
        else if (note[noteIdx] == 'S') currNote = 2;
        else if (note[noteIdx] == 'D') currNote = 6;
        else if (note[noteIdx] == 'L' && note[noteIdx + 1] == 'D') currNote = 1, noteIdx++;
        else if (note[noteIdx] == 'L' && note[noteIdx + 1] == 'U') currNote = 7, noteIdx++;
        else if (note[noteIdx] == 'R' && note[noteIdx + 1] == 'U') currNote = 9, noteIdx++;
        else if (note[noteIdx] == 'R' && note[noteIdx + 1] == 'D') currNote = 3, noteIdx++;

        noteIdx++;
        if (noteIdx < note.size() && note[noteIdx] == '!') {
            currNote = 10 - currNote;
            noteIdx++;
        }
    }

    int n = arrIdx;

    string input;
    cin >> input;

    int m = input.size();

    int cursor = 0;
    for (int i = 0; i < m; i++) {
        int dir = getDirection(input[i]);
        if (cursor == n || dir != arr[cursor])
            cursor = 0;
        else
            cursor++;
    }

    cout << (cursor == n ? "Yes" : "No") << '\n';

    return 0;
}
