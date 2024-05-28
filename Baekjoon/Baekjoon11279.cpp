// Baekjoon11279.cpp
#include <iostream>

#include <vector>

using namespace std;

class MaxHeap {
    int size;
    vector<int> arr;

    void Swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void Heapify(int me) {
        int leftChild = me * 2, rightChild = me * 2 + 1;

        int maxIdx;
        if (size < leftChild)
            return;
        else if (size < rightChild)
            maxIdx = leftChild;
        else
            maxIdx = (arr[leftChild] < arr[rightChild]) ? rightChild : leftChild;

        if (arr[maxIdx] > arr[me]) {
            Swap(arr[maxIdx], arr[me]);
            Heapify(maxIdx);
        }
    }

public:
    MaxHeap(int n) {
        size = 0;
        arr = vector<int> (n + 1);
    }

    void push(int x) {
        arr[++size] = x;

        int me = size, mom = size / 2;
        while (me != 1 && arr[mom] < arr[me]) {
            Swap(arr[me], arr[mom]);
            me = mom;
            mom /= 2;
        }
    }

    int pop() {
        if (size == 0)
            return 0;

        int result = arr[1];

        arr[1] = arr[size--];
        Heapify(1);

        return result;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    MaxHeap heap(t);
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