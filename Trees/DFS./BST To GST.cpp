/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
   map<int,int>mpp;
    void inorder(Node* root,vector<int>&arr){
        if(root==nullptr) return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    void trav(Node* root){
        if(root==nullptr) return;
        trav(root->left);
        root->data=mpp[root->data];
        trav(root->right);
    }
    void transformTree(Node *root) {
        // code here
        if(root==nullptr){
            return;
        }
        vector<int>arr;
        inorder(root,arr);
       
        int n=arr.size();
        int sufsum=arr[n-1];
       //reverse(arr.begin(),arr.end());
        mpp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
             mpp[arr[i]]=sufsum;
             sufsum+=arr[i];
        }
        trav(root);
        
        
    }

Time	O(n log n)
Space	O(n)


/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
   int sum=0;
    void transformTree(Node *root) {
        // code here
        if(root!=nullptr){
            transformTree(root->right);
            sum += root->data;
            root->data = sum - root->data;
            transformTree(root->left);
        }
        
    }
};
};
