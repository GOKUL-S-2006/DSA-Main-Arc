Choose a pivot element from the array

Partition the array:

Elements smaller than pivot → left side

Elements greater than pivot → right side

Recursively apply the same steps to the left and right subarrays

When subarrays have 0 or 1 element, they are already sorted


Code:
#include <iostream>
using namespace std;

void quickSort(int a[], int l, int r) {
    int i = l, j = r;
    int pivot = a[(l + r) / 2];   // middle element

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {
    int a[] = {8, 3, 1, 7, 0, 10, 2};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}



⏱ Complexity

Average / Best: O(n log n)

Worst: O(n²)

Space: O(log n) (recursion)



  
