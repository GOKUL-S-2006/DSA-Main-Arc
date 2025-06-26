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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        int val=0;
        ListNode *temp1;
        for(int i=0;i<k-1;i++)
        {
            fast=fast->next;
        }
        temp1=fast;
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
       int temp=slow->val;
       slow->val=temp1->val;
       temp1->val=temp;
       return head;
        
        




    }
};
