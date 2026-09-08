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


 /*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        if (head == nullptr || head->next == nullptr)
                return true;

            // Find middle
            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            // Reverse second half
            Node* prev = nullptr;
            Node* curr = slow;

            while (curr != nullptr) {
                Node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Compare first half and reversed second half
            Node* first = head;
            Node* second = prev;

            while (second != nullptr) {
                if (first->data != second->data)
                    return false;

                first = first->next;
                second = second->next;
            }

            return true;
        
        
    }
};


Time: O(n)
Space: O(1) extra space
