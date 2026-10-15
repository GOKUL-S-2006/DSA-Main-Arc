/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    ListNode* findk(ListNode* temp,int k){
          k--;
          while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
          }
          return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=nullptr;
        ListNode* nextNode;
        while(temp!=nullptr){
            ListNode* knode=findk(temp,k);
            if(knode==nullptr){
              if(prevNode) prevNode->next=temp;
             break;
            }
            nextNode=knode->next;
            knode->next=nullptr;
            reverseList(temp);
            if(temp==head){
                head=knode;
            }
            else{
                prevNode->next=knode;
            }
            prevNode=temp;
            temp=nextNode;
            

        }

        return head;
        


}
};


TC: \(O(n)\)



SC: \(O(1)\) 
