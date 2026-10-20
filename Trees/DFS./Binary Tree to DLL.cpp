/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    void inorder(Node* root,Node* &prev,Node* & head){
        if(root==nullptr) return;
        
        inorder(root->left,prev,head);
        
        if(prev==nullptr){
            head=root;
        }
        //if prev not null
        else{
          
          prev->right=root;
          root->left=prev;
            
        }
        prev=root;
        
        inorder(root->right,prev,head);
    }
    Node* treeToDLL(Node* root) {
        // code here
        Node* prev=nullptr;
        Node* head=nullptr;
        inorder(root,prev,head);
        return head;
        
    }


TC:O(N)
SC;O(H)

};|||
