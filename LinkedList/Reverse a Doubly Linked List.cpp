Brute Force:

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        stack<int>st;
        if(head==nullptr){
            return head;
        }
        Node* cur=head;
        while(cur!=nullptr){
            st.push(cur->data);
            cur=cur->next;
        }
        
        cur=head;
        while(!st.empty()){
            cur->data=st.top();
            st.pop();
            cur=cur->next;
        }
        return head;
        
    }
};

TC:O(2N)
SC:O(N)

Optimized

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* prevNode=nullptr;
        Node* cur=head;
        while(cur!=nullptr){
            prevNode=cur->prev;
            cur->prev=cur->next;
            cur->next=prevNode;
            
            cur=cur->prev;
        }
        head=prevNode->prev;
        return head;
    }
};
TC:O(N)
SC:O(1)



