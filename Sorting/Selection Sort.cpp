int getMaxIndex(vector<int>& arr, int last) {
    int maxIndex = 0;
    for(int i = 1; i <= last; i++) {
        if(arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n - 1; i++) {
        int last = n - i - 1;
        int maxIndex = getMaxIndex(arr, last);

        // Swap the max element to its correct (last) position
        swap(arr[maxIndex], arr[last]);
    }
}


| Complexity | Value        |
| ---------- | ------------ |
| Time       | O(n²)        |
| Space      | O(1)         |
| Stability  | ❌ Not Stable |


🔹 What is Stability in Sorting?

A sorting algorithm is called Stable if it preserves the relative order of elements with equal values.

👉 Means: if two elements have the same key/value, after sorting they should appear in the same order as they were originally.



Why Does Stability Matter?

Stability matters when sorting records by multiple keys.

Example:
Sort students by class, then by name.

If the first sorting (by class) is stable, the relative name order stays correct.

In databases, spreadsheets, or interview multi-level sorts → Stability is crucial.

  


  


  
