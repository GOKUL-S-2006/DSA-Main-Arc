*
**
***
****
*****


#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}


1
12
123
1234
12345


#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}

******
*****
****
***
**
*



#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}



*
**
***
****
*****
*****
****
***
**
*

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}


*
**
***
****
*****
******
****
***
**
*

#include <iostream>
using namespace std;

int main() {
    int n = 6;

    for(int row = 1; row <= 2 * n - 1; row++) {
        int stars;

        if(row <= n)
            stars = row;           // increasing
        else
            stars = 2 * n - row - 1; // decreasing (skip 5)

        for(int col = 1; col <= stars; col++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}


    *
   ***
  *****
 *******
*********



#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int row = 1; row <= n; row++) {

        // print spaces
        for(int col = 1; col <= n - row; col++) {
            cout << " ";
        }

        // print stars
        int stars = 2 * row - 1;
        for(int col = 1; col <= stars; col++) {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}




*********
 *******
  *****
   ***
    *



#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int row = n; row >=1; row--) {

        // print spaces
        for(int col = 1; col <= n - row; col++) {
            cout << " ";
        }

        // print stars
        int stars = 2 * row - 1;
        for(int col = 1; col <= stars; col++) {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}











Time Complexity (TC): O(n²) 
