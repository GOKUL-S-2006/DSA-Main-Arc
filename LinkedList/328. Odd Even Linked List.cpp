Brute Force-1


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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==nullptr)
        {
            return head;
        }
        ListNode* temp=head;
        vector<int>arr;
        while(temp!=NULL && temp->next!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) arr.push_back(temp->val);
        temp=head->next;
        while(temp!=NULL && temp->next!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) arr.push_back(temp->val);
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;


    }
};
TC:O(2N)
SC;O(N)

Brute Force-2:

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        vector<int>arr;
        int c=1;
        int odc=0;
        while(temp!=NULL)
        {
            if(c%2!=0)
            {
                arr.emplace(arr.begin(),temp->val);
                odc++;
            }
            else
            {
                arr.push_back(temp->val);
            }
            c++;
            temp=temp->next;
        }
        reverse(arr.begin()+0,arr.begin()+odc);
        ListNode* temp2=head;
        int i=0;
        while(temp2!=NULL)
        {
            temp2->val=arr[i];
            i++;
            temp2=temp2->next;
        }
        return head;

    }
};
Optimized Appproch:

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==nullptr)
        {
            return head;
        }
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode* evenh=head->next;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenh;
        return head;


    }
};
TC:O(N)
SC:O(1)
