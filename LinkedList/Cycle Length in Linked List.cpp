#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int cycleLength(Node* head) {

    unordered_map<Node*, int> visited;

    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {

        if (visited.find(temp) != visited.end()) {
            return count - visited[temp];
        }

        visited[temp] = count;

        count++;
        temp = temp->next;
    }

    return 0;   // No cycle
}

int main() {

    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    // 5 -> 3
    head->next->next->next->next->next =
        head->next->next;

    cout << "Cycle length: " << cycleLength(head);

    return 0;
}


Time: O(n)
Space: O(n) because of the HashMap.



/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        int len=0;
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                Node* temp=fast->next;
                len++;
                while(temp!=fast){
                    temp=temp->next;
                    len++;
                }
                return len;
            }
        }
        return len;
    }
};


Time omplexity
Time: O(n)
Space: O(1)

