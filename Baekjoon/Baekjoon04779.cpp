// Baekjoon04779.cpp
#include <cstdio>

#include <string>

using namespace std;

string cantor;

void solve(string& str, int start, int end) {
    if (start != end) {
        int third = (end - start + 1) / 3;
        for (int i = start + third; i < start + third * 2; i++)
            cantor[i] = ' ';

        solve(str, start, start + third - 1);
        solve(str, start + third * 2, end);
    }
}

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int n3 = 1;
        for (int i = 0; i < n; i++)
            n3 *= 3;

        cantor = string(n3, '-');

        solve(cantor, 0, n3 - 1);
    
        printf("%s\n", cantor.c_str());
    }

    return 0;
}