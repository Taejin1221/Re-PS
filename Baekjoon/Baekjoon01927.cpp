// Baekjoon01927.cpp
#include <iostream>

#include <vector>

using namespace std;

class MinHeap {
    vector<int> heap;
    int size;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int me) {
        int leftChild = me * 2, rightChild = me * 2 + 1;

        int minIdx;
        if (rightChild <= size)
            minIdx = (heap[leftChild] < heap[rightChild]) ? leftChild : rightChild;
        else if (leftChild <= size)
            minIdx = leftChild;
        else
            return;
        
        if (heap[me] > heap[minIdx]) {
            swap(heap[me], heap[minIdx]);

            heapify(minIdx);
        }
    }

public:
    MinHeap(int n): heap(vector<int> (n + 1)), size(0) { }

    void push(int n) {
        heap[++size] = n;

        int me = size;
        for (; me / 2 > 0 && heap[me / 2] > heap[me]; me /= 2)
            swap(heap[me], heap[me / 2]);
    }

    int pop() {
        if (size == 0)
            return 0;
        else {
            int result = heap[1];
            heap[1] = heap[size--];

            heapify(1);

            return result;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    MinHeap pq = MinHeap(t);
    while (t--) {
        int n;
        cin >> n;

        if (n == 0)
            cout << pq.pop() << '\n';
        else
            pq.push(n);
    }

    return 0;
}