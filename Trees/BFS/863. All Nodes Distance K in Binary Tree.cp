
class Solution {
public:
    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& par) {
        queue<TreeNode*> q;
        q.push(root);
        par[root] = nullptr;

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left) {
                par[cur->left] = cur;
                q.push(cur->left);
            }

            if (cur->right) {
                par[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        buildParent(root, par);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty() && dist < k) {
            int sz = q.size();

            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !vis.count(cur->left)) {
                    vis.insert(cur->left);
                    q.push(cur->left);
                }

                if (cur->right && !vis.count(cur->right)) {
                    vis.insert(cur->right);
                    q.push(cur->right);
                }

                if (par[cur] && !vis.count(par[cur])) {
                    vis.insert(par[cur]);
                    q.push(par[cur]);
                }
            }

            dist++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};


