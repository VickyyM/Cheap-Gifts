#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void merge(int arr[], int const l, int const m, int const r)
{
    auto const subArrayOne = m - l + 1;
    auto const subArrayTwo = r - m;
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[l + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[m + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = l;


    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int arr[], int const l, int const r)
{
    if (l >= r)
        return;

    auto m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}



int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    int k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    mergeSort(arr, 0, n - 1);
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum + arr[i];
    }
    cout << sum << endl;

    return 0;
}

