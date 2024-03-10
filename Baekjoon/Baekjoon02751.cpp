// Baekjoon02751.cpp
#include <iostream>

#include <vector>

using namespace std;

int copyArr[1'000'000];

void Merge(int arr[], int start, int mid, int end) {
    for (int i = start; i <= end; i++)
        copyArr[i] = arr[i];

    int idx = start, leftIdx = start, rightIdx = mid + 1;
    while (leftIdx <= mid && rightIdx <= end)
        arr[idx++] = (copyArr[leftIdx] < copyArr[rightIdx]) ? copyArr[leftIdx++] : copyArr[rightIdx++];

    while (leftIdx <= mid)
        arr[idx++] = copyArr[leftIdx++];
    
    while (rightIdx <= end)
        arr[idx++] = copyArr[rightIdx++];
}

void MergeSort(int arr[], int start, int end) {
    if (start != end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[1'000'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}