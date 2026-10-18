/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  Node* findTarget(Node* root,map<Node*,Node*>&parent,int target){
      queue<Node*>q;
      Node* start=nullptr;
      q.push(root);
      while(!q.empty()){
          Node* cur=q.front();
          if(cur->data==target){
              start=cur;
          }
          q.pop();
          if(cur->left){
              q.push(cur->left);
              parent[cur->left]=cur;
           }
           if(cur->right){
              q.push(cur->right);
              parent[cur->right]=cur;
           }
           
           
      }
      return start;
  }
  
  int minburn(Node* start,map<Node*,Node*>&parent){
      int time=-1;
      queue<Node*>q;
      set<Node*>vis;
      q.push(start);
      vis.insert(start);
      while(!q.empty()){
          int s=q.size();
          time++;
          while(s--){
              Node* cur=q.front();
              q.pop();
              
              //Burn left child
              if(cur->left && !vis.count(cur->left)){
                  q.push(cur->left);
                  vis.insert(cur->left);
              }
              //Burn right child
               if(cur->right && !vis.count(cur->right)){
                  q.push(cur->right);
                  vis.insert(cur->right);
              }
              
              //Burn parent
              if(parent[cur] && !vis.count(parent[cur])){
                  q.push(parent[cur]);
                  vis.insert(parent[cur]);
              }
          }
      }
      
      return time;
      
  }
  
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*>parent;
        Node* start=findTarget(root,parent,target);
        int ans=minburn(start,parent);
        return ans;
        
        
    }
};
Complexity: \(O(N)\) time and \(O(N)\) space.
CP pattern: Parent mapping + BFS + visited set.

