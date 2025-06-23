#include <bits/stdc++.h>
using namespace std;

// Function to find the celebrity
int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();

    vector<int>  knowme(n, 0), iknow(n, 0);

    // query for all edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             knowme[j]++;
             iknow[i]++;
        }
    }

    
    for (int i = 0; i < n; i++)
        if (knowme[i] == n - 1 && iknow[i] == 0)
            return i;

    return -1;
}

int main() {
    vector<vector<int> > mat = {{ 0, 1, 0 },
                                { 0, 0, 0 },
                                { 0, 1, 0 }};
    cout << celebrity(mat);
    return 0;
}

O(n^2) Time and O(n) Space

// C++ program to find celebrity
#include <bits/stdc++.h>
using namespace std;

// Function to find the celebrity
int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();

    int top = 0, down = n - 1;
    while (top < down) {
        
        // j knows i, thus j can't be celebrity
        if (mat[j][i] == 1) 
            j--;

        // else i can't be celebrity
        else
            i++;
    }

    // i points to our celebrity candidate
    int c = i;

    // Check if c is actually
    // a celebrity or not
    for (i = 0; i < n; i++) {
        if(i == c) continue;

        // If any person doesn't
        // know 'c' or 'c' doesn't
        // know any person, return -1
        if (mat[c][i] || !mat[i][c])
            return -1;
    }

    return c;
}

int main() {
    vector<vector<int> > mat = {{ 0, 1, 0 },
                                { 0, 0, 0 },
                                { 0, 1, 0 }};
    cout << celebrity(mat);
    return 0;
}

