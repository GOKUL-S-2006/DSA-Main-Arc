#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();

    // Left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    vector<int> left(n);

    // Right[i] contains height of tallest bar to
    // the right of i'th bar including itself
    vector<int> right(n);

    int res = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    for (int i = 1; i < n - 1; i++) {
        int minOf2 = min(left[i], right[i]);
            res += minOf2 - arr[i];
    }

    return res;
}

int main() {
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr);
    return 0;
}
O(3N) Time and O(2n) Space

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxWater(vector<int>& arr) {
    stack<int> st;  
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
       
        // Pop all items smaller than arr[i]
        while (!st.empty() && arr[st.top()] < arr[i]) {          
            
            int pop_height = arr[st.top()];
            st.pop();
          
            if (st.empty())
                break;

            // arr[i] is the next greater for the removed item
            // and new stack top is the previous greater 
            int distance = i - st.top() - 1;
          
            // Take the minimum of two heights (next and prev greater)
            // and find the amount of water that we can fill in all
            // bars between the two
            int water = min(arr[st.top()], arr[i]) - pop_height;

            res += distance * water;
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr);
    return 0;
}
Using Stack - O(n) Time and O(n) Space
