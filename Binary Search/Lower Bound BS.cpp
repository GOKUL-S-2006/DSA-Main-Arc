// C++ Program to count the elements smaller and larger than
// a value in a vector using lower_bound() and upper_bound()
#include <bits/stdc++.h>
using namespace std;

int main() {
  	vector<int> v = {11, 34, 56, 67, 89};
  	int val = 50;
  
  	// Finding lower and upper boud of val in v
  	auto lb = lower_bound(v.begin(), v.end(), val);
  	auto up = upper_bound(v.begin(), v.end(), val);
  	
  	// Finding the number of smaller elements
    cout << "No. of Smaller Elements: " << lb - v.begin()
      	<< endl;
  
    // Finding the number of larger elements
  	cout << "No. of Larger Elements: " << v.end() - up
      << endl;

  	return 0;
}
