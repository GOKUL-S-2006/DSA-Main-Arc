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



Approach II:(It Will reduce the time compexity of using the stack)

Key idea: 
      ->First Reverse a Given Linkedlist
      ->start calulating and multiply each number by 2 if the number exceeds 9 which means greater than 9 you should store unit digit in new node and remaining in the carry everytime don'tforget to add the carry with your sum
      ->At last if there is ant carry add them up in a new Node attach it in last node

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
    ListNode* doubleIt(ListNode* head) {

        head=reverseList(head);

        ListNode *dummy=new ListNode(-1);

        ListNode* curr=dummy;

        int carry=0;
        int sum=0;

        while(head!=nullptr){

            sum=carry;
            sum+=head->val*2;
            
            ListNode *newnode=new ListNode(sum%10);
            carry=sum/10;

            curr->next=newnode;
            curr=curr->next;

            head=head->next;
        }

        if(carry){
            ListNode *newnode=new ListNode(carry);
           
            curr->next=newnode;
            curr=curr->next;

        }


        dummy=dummy->next;
        dummy=reverseList(dummy);

        return dummy;
                
    }
};

Tc->O(3N)
SC->O(N)(for creating the new linked list that is un avoidable)
