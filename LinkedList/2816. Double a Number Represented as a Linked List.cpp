class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Step 1: Push all digits into the stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        int sum = 0;
        int carry = 0;
        ListNode* result = nullptr; // Start with empty result list

        // Step 2: Process the stack and build the list in correct order
        //Building the List from Tail to Head
        while (!st.empty()) {
            sum = carry + (st.top() * 2);
            st.pop();

            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = result;
            result = newNode;

            carry = sum / 10;
        }

        // Step 3: If carry remains, add it as a new head node
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = result;
            result = newNode;
        }

        return result;
    }
};
