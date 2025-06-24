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
        stack<int> st1, st2;

        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* result = nullptr;

        while (!st1.empty() || !st2.empty() || carry) {
            int sum = carry;

            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }

            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            // Prepend new node
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = result;
            result = newNode;

            carry = sum / 10;
        }

        return result;
    }
};

Stacks reverse the digits so we can do addition starting from the least significant digit.

We build the result list by prepending nodes (since most significant digit comes first).

We correctly handle carry propagation.

