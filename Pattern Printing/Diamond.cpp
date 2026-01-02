    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *



#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int row = 1; row <= 2*n - 1; row++) {

        int stars = (row <= n) 
                    ? (2*row - 1)
                    : (2*(2*n - row) - 1);

        int spaces = (2*n - 1 - stars) / 2;

        for(int col = 1; col <= spaces; col++) {
            cout << " ";
        }

        for(int col = 1; col <= stars; col++) {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}
