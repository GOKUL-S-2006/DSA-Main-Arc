#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.top();
    s.pop();
    s.size();
    s.empty();
    s.emplace(40);

    stack<int> s2;
    s2.push(100);
    s2.push(200);
    s.swap(s2);

    return 0;
}
