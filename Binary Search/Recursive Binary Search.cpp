// C++ program to implement recursive binary
// search
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& v, int low,
                  int high, int target) {
    
  	// If the range is invalid
    if (low > high) {
        return false;
    }

    // Finding mid point
    int mid = ((high - low) / 2) + low;

    // If the middle element is equal to target
    if (v[mid] == target) {
        return true;
    }

    // If the middle element is greater than
  	// target,  search in the left half
    if (v[mid] > target) {
        return binarySearch(v, low, mid - 1,
                            target);
    }

    // If the middle element is smaller than
  	// target, search in the right half
    return binarySearch(v, mid + 1, high,
                        target);
}

int main() {
    vector<int> v = {1, 5, 3, 2, 4, 9, 8, 11};

    // Element to be searched
    int target = 8;

    // Searching the target element using the
  	// recursive function
    if (binarySearch(v, 0, v.size() - 1,target)) {
        cout << target << " found.";
    } else {
        cout << target << " NOT found.";
    }
    return 0;
}
