// Baekjoon05522.cpp
#include <cstdio>

using namespace std;

int main(void) {
    int ans = 0;

    int temp;
    while (scanf("%d", &temp) != EOF) {
        ans += temp;
    }

    printf("%d\n", ans);

    return 0;
}