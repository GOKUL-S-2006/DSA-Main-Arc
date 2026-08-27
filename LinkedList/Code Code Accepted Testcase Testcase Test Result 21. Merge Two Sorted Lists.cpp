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
   
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if (l1 != nullptr)
            tail->next = l1;
        else
            tail->next = l2;


        return dummy.next;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=merge(list1,list2);
        return ans;
    }
};

Time: O(n + m)
Extra space: O(1) — we're reusing the existing nodes.
