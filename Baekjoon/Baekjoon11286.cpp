// Baekjoon11286.cpp
#include <iostream>

#include <vector>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

struct Node {
    int absVal, realVal;

    Node(): absVal(0), realVal(0) { }
    Node(int x): absVal(ABS(x)), realVal(x) { }

    bool operator<(const Node& n2) {
        return (absVal != n2.absVal ? absVal < n2.absVal : realVal < n2.realVal);
    }
};

class AbsHeap {
    vector<Node> heap;
    int size;

    void Swap(Node& a, Node& b) {
        Node temp = a;
        a = b;
        b = temp;
    }

    void Heapify(int me) {
        int leftChild = me * 2, rightChild = me * 2 + 1;

        int minIdx;
        if (rightChild <= size)
            minIdx = (heap[leftChild] < heap[rightChild]) ? leftChild : rightChild;
        else if (leftChild <= size)
            minIdx = leftChild;
        else
            return;

        if (heap[minIdx] < heap[me]) {
            Swap(heap[minIdx], heap[me]);
            Heapify(minIdx);
        }
    }

public:
    AbsHeap(int t) {
        size = 0;
        heap = vector<Node> (t + 1);
    }

    void push(int x) {
        heap[++size] = Node(x);

        int me = size, mom = size / 2;
        while (me != 1 && heap[me] < heap[mom]) {
            Swap(heap[me], heap[mom]);

            me = mom;
            mom /= 2;
        }
    }

    int pop() {
        if (size == 0)
            return 0;

        int result = heap[1].realVal;
        
        heap[1] = heap[size--];
        Heapify(1);

        return result;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    AbsHeap heap(t);
    while (t--) {
        int x;
        cin >> x;

        if (x == 0)
            cout << heap.pop() << '\n';
        else
            heap.push(x);
    }

    return 0;
}