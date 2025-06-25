Approach I:
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


Approach II:(Reduces the space complexity by not using a stack):

   Key Idea:
        ->Revrese a given two LinkedList
        ->Apply the logic which was used in Add two number I
        Again while return answer don't forget to reverse a answer linkedlist

class Solution {
public:
   ListNode *reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest of linked list and put
    //  the first element at the end
    ListNode *rest = reverseList(head->next);

    // Make the current head as last node of
    // remaining linked list
    head->next->next = head;

    // Update next of current head to NULL
    head->next = NULL;

    // Return the reversed linked list
    return rest;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

         l1=reverseList(l1);
         l2=reverseList(l2);

        ListNode *dummy=new ListNode(-1);
        ListNode* curr=dummy;

        int sum=0,carry=0;

        while(l1!=nullptr || l2!=nullptr){

            sum=carry;
            if(l1)sum+=l1->val;
            if(l2)sum+=l2->val;

            ListNode * newNode=new ListNode(sum%10);
            curr->next=newNode;
            curr=curr->next;
            carry=sum/10;

            if(l1)l1=l1->next;
            if(l2)l2=l2->next;

        }

        if(carry){
            ListNode * newNode=new ListNode(carry);
            curr->next=newNode;
            curr=curr->next;
        }
        dummy=dummy->next;
        dummy=reverseList(dummy);

        return dummy;


        
    }
};

Tc->O(4N)
SC->O(N) (For creating a new Linkedlist which is unavoidable)

