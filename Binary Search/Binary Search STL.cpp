// C++ program to illustrate how to use the
// std::binary_search() function
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 8, 9, 11};

    // Element to be searched
    int target = 8;
  
    // Check for the target in the vector v
    if (binary_search(v.begin(), v.end(), target)) {
      
        // If the value is found
        cout << target << " found.";
    } else {
      
        // If the value is not found
        cout << target << " NOT found.";
    }
    int arr[] = {1, 4, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;

    // Check if the element exists
    if (binary_search(arr, arr + n, k))
        cout << k << " is Present";
    else
        cout << k << " is NOT Present";
    return 0;
}
