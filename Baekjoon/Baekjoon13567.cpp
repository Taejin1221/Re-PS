// Baekjoon13567.cpp
#include <iostream>

#include <string>

using namespace std;

using pii = pair<int, int>;

int turnRobot(int direction, bool left) {
    if (left)
        direction++;
    else
        direction--;

    if (direction > 4)
        direction = 1;
    
    if (direction < 1)
        direction = 4;
    
    return direction;
}

pii moveRobot(pii currPos, pii instruction) {
    int direction = instruction.first, distance = instruction.second;
    if (direction == 1) // right
        currPos.first += distance;
    else if (direction == 2) // up
        currPos.second += distance;
    else if (direction == 3) // left
        currPos.first -= distance;
    else // down
        currPos.second -= distance;

    return currPos;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pii currPos = { 0, 0 }; // { x, y }
    int direction = 1;

    bool isValid = true;
    while (m--) {
        string oper;
        int value;
        cin >> oper >> value;

        if (isValid) {
            if (oper == "MOVE") {
                pii nextPos = moveRobot(currPos, { direction, value });
                if (!((0 <= nextPos.first && nextPos.first <= n) && (0 <= nextPos.second && nextPos.second <= n)))
                    isValid = false;
                else
                    currPos = nextPos;
            } else {
                direction = turnRobot(direction, value == 0);
            }
        }
    }

    if (isValid)
        cout << currPos.first << ' ' << currPos.second;
    else
        cout << -1;
    cout << '\n';

    return 0;
}