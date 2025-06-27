/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };\
 */
Brute Force:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        std::stack<int> st;
        ListNode* temp = head;

        // Push all values onto the stack
        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Replace each node's value by popping from the stack
        temp = head;
        while (temp) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};
TC;O(2N)
SC:O(N)

Optimal
class Solution {
public:
    ListNode* reverseList(ListNode* head)
     {
        ListNode *temp=head;
        ListNode* prev=NULL;
        ListNode* front;
        while(temp!=NULL)
        {
              front=temp->next;
              temp->next=prev;
              prev=temp;
              temp=front;
        }
        return prev;
    }
};
TC:O(N)
SC:O(1)
  
