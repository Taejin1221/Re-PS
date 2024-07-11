// Baekjoon05671.cpp
#include <cstdio>

using namespace std;

bool isUnlucky(int a) {
    bool digit[10] = { false, };
    while (a) {
        if (digit[a % 10])
            return true;
        digit[a % 10] = true;
        a /= 10;
    }

    return false;
}

int main(void) {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int ans = 0;
        for (int i = a; i <= b; i++)
            ans += (isUnlucky(i) == false);
        printf("%d\n", ans);
    }

    return 0;
}