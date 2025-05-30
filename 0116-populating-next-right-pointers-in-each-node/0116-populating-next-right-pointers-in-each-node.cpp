class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr; 
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left) 
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                if (prev) {
                    prev->next = curr;
                }
                prev = curr;
            }

            prev->next = nullptr;
        }

        return root;
    }
};
