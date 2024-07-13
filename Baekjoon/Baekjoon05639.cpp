// Baekjoon05639.cpp
#include <iostream>
#include <cstdio>

using namespace std;

using pii = pair<int, int>;

pii adjList[1'000'001];

void insert(int root, int num) {
    if (root > num) {
        if (adjList[root].first == 0)
            adjList[root].first = num;
        else
            insert(adjList[root].first, num);
    } else {
        if (adjList[root].second == 0)
            adjList[root].second = num;
        else
            insert(adjList[root].second, num);
    }
}

void postorder(int curr) {
    if (adjList[curr].first != 0)
        postorder(adjList[curr].first);
    
    if (adjList[curr].second != 0)
        postorder(adjList[curr].second);

    printf("%d\n", curr);
}

int main(void) {
    int root, curr;
    scanf("%d", &root);
    for (int i = 0; scanf("%d", &curr) != EOF; i++)
        insert(root, curr);

    postorder(root);

    return 0;
}