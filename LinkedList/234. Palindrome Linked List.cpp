Brute Force:

 bool isPalindrome(ListNode* head) {
        // if head is null and you have the only one element in the given node
        // they are always the palindrome
        if (head == NULL || head->next == NULL)
            return true;

        stack<int> st;

        ListNode* temp = head;
        // push all the element in the stack so that you will get the last
        // element in top of the stack to compare
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        ListNode* temp1 = head;

        // check top element== current element of the list if so then pop the
        // top element and move ahead of not return the false
        while (temp1 != NULL) {

            if (temp1->val != st.top())
                return false;
            st.pop();
            temp1 = temp1->next;
        }
        return true;
}
TC->O(3N)
SC->O(N)
