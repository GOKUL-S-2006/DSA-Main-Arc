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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead=new ListNode(-1);
        ListNode* cur=dummyhead;
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int sum=0;
        while(temp1!=NULL || temp2!=NULL)
        {
            sum=carry;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            cur->next=newNode;
            cur=cur->next;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;

     }
       if(carry)
       {
           ListNode* newNode=new ListNode(carry);
           cur->next=newNode;
       }
     return dummyhead->next;
    }
};
N1,N2->>SIZE OF LINKED LIST L1,L2 RESPECTIVELY
TC:O(MAX(N1,N2))
SC;O(MAX(N1,N2))
