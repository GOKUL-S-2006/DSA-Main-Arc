SOLN-1>>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
    return {-1, -1};
}
        vector<int>arr;
        ListNode *prev_node=head;
         ListNode *cur=head->next;
        ListNode *next_node=cur->next;
        int index=1;
        while(next_node!=nullptr){
            if(cur->val > prev_node->val && cur->val>next_node->val ||  cur->val< prev_node->val && cur->val<next_node->val){
                 arr.push_back(index);
            }
            prev_node=cur;
            cur=cur->next;
            next_node=cur->next;
            index++;
        }
        
        if(arr.size()<2){
            return {-1,-1};
        }
        int max_val=arr[arr.size()-1]-arr[0];
        int min_val=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            min_val=min(min_val,arr[i+1]-arr[i]);
        }
        return {min_val,max_val};

       
    }
};
TC;O(N)
SC:O(n)



Soln-->>2
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        int index = 1;
        int first_cp = -1, last_cp = -1, prev_cp = -1;
        int min_dist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        while (next) {
            bool is_critical = (curr->val > prev->val && curr->val > next->val) ||
                               (curr->val < prev->val && curr->val < next->val);

            if (is_critical) {
                if (first_cp == -1)
                    first_cp = index;
                else {
                    min_dist = min(min_dist, index - prev_cp);
                    last_cp = index;
                }
                prev_cp = index;
            }

            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (first_cp == last_cp || last_cp == -1)
            return {-1, -1};

        return {min_dist, last_cp - first_cp};
    }
};


TC;O(N)
SC;O(1)




