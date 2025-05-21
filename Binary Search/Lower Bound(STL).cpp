// C++ Program to illustrate use of std::lower_bound()
// and std::upper_bound() for vector
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {11, 34, 56, 67, 89};

  	// Finding lower bound of 56
    cout << *lower_bound(v.begin(), v.end(), 56)
      << endl;
	
  	// Finding upper bound of 56
    cout << *upper_bound(v.begin(), v.end(), 56);
    return 0;
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
}

