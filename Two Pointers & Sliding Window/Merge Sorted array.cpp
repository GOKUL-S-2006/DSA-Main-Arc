#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(int arr1[], int arr2[], int n, int m) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // Copy remaining elements
    while (i < n) {
        result.push_back(arr1[i]);
        i++;
    }
    while (j < m) {
        result.push_back(arr2[j]);
        j++;
    }

    cout << "Merged array: ";
    for(int x : result) cout << x << " ";
}

int main() {
    int arr1[] = {1,4,7,8};
    int arr2[] = {2,3,6,9};
    int n = 4, m = 4;

    mergeSortedArrays(arr1, arr2, n, m);

    return 0;
}
Explanation:

We are given two sorted arrays, and we need to merge them into a single sorted array. Since both arrays are already sorted, we use the Two-Pointer technique to merge them efficiently.

We keep one pointer i on the first array and another pointer j on the second array. At each step, we compare the two elements and push the smaller one into a new result array. Whichever element we use, we move its pointer forward.

This works in linear time O(n+m) because each pointer only moves forward once and never goes backward.
In the end, if any elements remain in either array, we append them because they are already sorted.

So, the Two-Pointer method gives us an efficient merge in O(n+m) time using extra space O(n+m).





