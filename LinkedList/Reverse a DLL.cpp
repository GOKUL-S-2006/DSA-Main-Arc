/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==NULL || head->next==nullptr)
        {
            return head;
        }
        DLLNode* previ=NULL;
        DLLNode* cur=head;
        while(cur!=nullptr)
        {
            previ=cur->prev;
            cur->prev=cur->next;
            cur->next=previ;
            cur=cur->prev;
            
            
        }
        IT WILL POINT TO SECOND NODE AT END SO WE RETURN SECOND NODE PREV WHICH IS NEW HEAD
        return previ->prev;
    }
};
TC:O(N)
SC:O(1)
