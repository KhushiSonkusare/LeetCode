class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> colMap; // hd -> {{level, value}, ...}
        queue<pair<TreeNode*, pair<int, int>>> q; // node, {hd, level}
        
        if (root == nullptr) return {};

        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* node = front.first;
            int hd = front.second.first;
            int level = front.second.second;
            
            colMap[hd].push_back({level, node->val});
            
            if (node->left)
                q.push({node->left, {hd - 1, level + 1}});
            if (node->right)
                q.push({node->right, {hd + 1, level + 1}});
        }

        vector<vector<int>> result;
        
        for (auto& [hd, vec] : colMap) {
            // Sort by level first, then value
            sort(vec.begin(), vec.end());
            vector<int> col;
            for (auto& [lvl, val] : vec)
                col.push_back(val);
            result.push_back(col);
        }

        return result;
    }
};
