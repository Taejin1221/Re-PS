// Baekjoon24060.cpp
#include <iostream>

using namespace std;

int k, currStore, ans = -1;

int temp[500'000];

void Merge(int arr[], int start, int mid, int end) {
    int leftIdx = start, rightIdx = mid + 1, tempIdx = 0;
    while (leftIdx <= mid && rightIdx <= end)
        temp[tempIdx++] = (arr[leftIdx] <= arr[rightIdx]) ? arr[leftIdx++] : arr[rightIdx++];
    
    while (leftIdx <= mid)
        temp[tempIdx++] = arr[leftIdx++];
    
    while (rightIdx <= end)
        temp[tempIdx++] = arr[rightIdx++];

    leftIdx = start, tempIdx = 0;
    while (leftIdx <= end) {
        currStore++;
        if (currStore == k)
            ans = temp[tempIdx];
        arr[leftIdx++] = temp[tempIdx++];
    }
}

void MergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> k;

    int arr[500'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    cout << ans << '\n';

    return 0;
}