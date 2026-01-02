 1
   212
  32123
 4321234
543212345



  #include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int row = 1; row <= n; row++) {

        // spaces
        for(int col = 1; col <= n - row; col++) {
            cout << " ";
        }

        // left part (row → 1)
        for(int col = row; col >= 1; col--) {
            cout << col;
        }

        // right part (2 → row)
        for(int col = 2; col <= row; col++) {
            cout << col;
        }

        cout << endl;
    }
    return 0;
}




    1
   212
  32123
 4321234
543212345
 4321234
  32123
   212
    1




 #include <iostream>
using namespace std;

int main() {
    int n = 5;

    // Upper half (including middle)
    for(int row = 1; row <= n; row++) {

        // spaces
        for(int col = 1; col <= n - row; col++) {
            cout << " ";
        }

        // left part (row → 1)
        for(int col = row; col >= 1; col--) {
            cout << col;
        }

        // right part (2 → row)
        for(int col = 2; col <= row; col++) {
            cout << col;
        }

        cout << endl;
    }

    // Lower half
    for(int row = n - 1; row >= 1; row--) {

        for(int col = 1; col <= n - row; col++) {
            cout << " ";
        }

        for(int col = row; col >= 1; col--) {
            cout << col;
        }

        for(int col = 2; col <= row; col++) {
            cout << col;
        }

        cout << endl;
    }

    return 0;
}
