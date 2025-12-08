void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

Time complexity:
O(n^2)


| Property     | Value                    |
| ------------ | ------------------------ |
| Stable       | ✔ Yes                    |
| In-place     | ✔ Yes                    |
| Good for     | Small datasets, teaching |
| Not good for | Large datasets           |


  | Space    | Explanation                           |
| -------- | ------------------------------------- |
| **O(1)** | Sorting done in-place, no extra array |
