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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        stack<ListNode*> st;
        ListNode* cur = head;
        int n = 0;

        // push all nodes
        while(cur){
            st.push(cur);
            cur = cur->next;
            n++;
        }

        cur = head;

        // only n/2 iterations needed
        for(int i = 0; i < n/2; i++){
            ListNode* topNode = st.top();
            st.pop();

            ListNode* temp = cur->next;

            cur->next = topNode;
            topNode->next = temp;

            cur = temp;  // move to next original node
        }

        // 🔥 CRITICAL
        cur->next = nullptr;
    }
};
