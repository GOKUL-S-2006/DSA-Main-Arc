/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       
        if (root == nullptr) {
            
            return root; 
        }
        
        //vectot<Node*>ans;
        queue<Node*> q; 
        
        q.push(root); 

        while (!q.empty()) {
           
            int size = q.size(); 
            
            vector<Node*> level; 

            for (int i = 0; i < size; i++) {
                
                Node* node = q.front(); 
                
                q.pop(); 
                
                level.push_back(node); 

               
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            for(int i=0;i<level.size()-1;i++){
                level[i]->next=level[i+1];
                
            }
            level[level.size()-1]->next=nullptr; 
        }
        
      
        return root; 
    }
};
TC:O(N)
SC:O(N)
APPROACH 2:(Using O(1) Space)



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        Node *leftmost=root;
        Node *cur;
        while(leftmost && leftmost->left){
            cur=leftmost;
            while(cur!=nullptr){
                cur->left->next=cur->right;
                if(cur->next!=nullptr){
                    cur->right->next=cur->next->left;
                }
                cur=cur->next;
            }
          leftmost=leftmost->left;

        }
        return root;

    }
};

  
