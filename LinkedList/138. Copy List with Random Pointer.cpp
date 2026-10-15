/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur=head;
        Node* dummy=new Node(-1);
        dummy->next=nullptr;
        Node* tail=dummy;
       
        map<Node*,Node*>mpp;
        Node* newNode;
        while(cur!=nullptr){
             newNode=new Node(cur->val);
             tail->next=newNode;
             tail=newNode;
             mpp[cur]=newNode;
             cur=cur->next;
             
       }
      Node* Chead=dummy->next;
       cur=head;
       Node* cur2=Chead;
       while(cur!=nullptr){
       
          if(cur->random!=nullptr){
                  cur2->random=mpp[cur->random];
           }
           else{
            cur2->random=nullptr;
           }
           cur=cur->next;
           cur2=cur2->next;
       }

       return Chead;

    
    }

Complexity:
- Time: \(O(n\log n)\) using map; use unordered_map<Node*, Node*> for expected \(O(n)\).
- Space: \(O(n)\) for the map and copied nodes.
};
