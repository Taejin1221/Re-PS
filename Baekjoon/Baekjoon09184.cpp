// Baekjoon09184.cpp
#include <cstdio>

#define BLANK 0x3f3f3f3f

using namespace std;

int dp[21][21][21];

int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);
    else {
        if (dp[a][b][c] == BLANK) {
            if (a < b && b < c)
                dp[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
            else
                dp[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
        }

        return dp[a][b][c];
    }
}

int main(void) {
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j <= 20; j++)
            for (int k = 0; k <= 20; k++)
                dp[i][j][k] = BLANK;

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    while (!(a == -1 && b == -1 && c == -1)) {
        printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
        scanf("%d %d %d", &a, &b, &c);
    }

    return 0;
}