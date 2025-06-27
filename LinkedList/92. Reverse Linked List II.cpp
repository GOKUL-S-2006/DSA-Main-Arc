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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int position = 1;
        ListNode* curr = head;
        ListNode* startNode = nullptr;       // Node at position 'left'
        ListNode* endNode = nullptr;         // Node at position 'right'
        ListNode* prev = nullptr;            // Used for reversing
        ListNode* nextNode = nullptr;        // Temporarily stores next pointer
        ListNode* beforeStart = nullptr;     // Node before 'left'
        ListNode* afterEnd = nullptr;        // Node after 'right'
        bool reversed = false;

        while (curr != nullptr) {
            reversed = false;

            if (position < left) {
                beforeStart = curr;
            }

            if (position == left) {
                startNode = curr;
                prev = curr;
            }

            if (position == right) {
                endNode = curr;
            }

            if (position == right + 1) {
                afterEnd = curr;
            }

            if (position > left && position <= right) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                reversed = true;
            }

            if (!reversed) {
                curr = curr->next;
            }

            position++;
        }

        if (beforeStart != nullptr) {
            beforeStart->next = endNode;
        } else {
            head = endNode;
        }

        startNode->next = afterEnd;

        return head;
    }
};
Metric	Complexity
Time Complexity	O(n)
Space Complexity	O(1)
