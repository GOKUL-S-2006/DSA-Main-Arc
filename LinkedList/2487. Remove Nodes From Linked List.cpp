note:-Convert the problem to finding the next greater element in the stack simillar

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        // GO deeper solve for the one node , two node , three ...
        ListNode* newHead = reverseList(head->next);

        // store the head next
        ListNode* front = head->next;

        // front next would be pointing to the head
        front->next = head;

        // head next would be pointing to the nullptr
        head->next = nullptr;

        return newHead;
    }
    //The idea is think about the finding the next greater element in the stack same problem
    ListNode* removeNodes(ListNode* head) {

        //edge case
        if (head == nullptr || head->next == nullptr)  return head;
        
        //reverse a linkedlist
        head = reverseList(head);

        
        ListNode* temp = head;
       
         //Store the last element in the maxi value which means last element is always greater 
        int maxi = head->val;

        while (temp != nullptr && temp->next != nullptr) {

            //if next element is <maxi remove until you see temp->next > maxi    
            if (temp->next->val < maxi) {

                ListNode* toremove = temp->next;

                temp->next = toremove->next;

            } 
            //or else there is greater element is presented so update maxi and move to the next greater element
            else {
                temp = temp->next;
                maxi = max(temp->val, maxi);
            }
        }

        //finally don't forget to reverse the linkedlist to return answer
        head = reverseList(head);

        return head;
    }

    //TC->O(3N)
    //SC->O(1)
};
