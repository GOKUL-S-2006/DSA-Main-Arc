class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                s += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                s += "#,";
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;

        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if (getline(ss, val, ',')) {
                if (val == "#") {
                    curr->left = nullptr;
                } else {
                    curr->left = new TreeNode(stoi(val));
                    q.push(curr->left);
                }
            }

            // Right child
            if (getline(ss, val, ',')) {
                if (val == "#") {
                    curr->right = nullptr;
                } else {
                    curr->right = new TreeNode(stoi(val));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};
