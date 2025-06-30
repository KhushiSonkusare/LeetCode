class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int node, vector<int> &visited) {
        stack<int> st;
        st.push(node);

        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            if (!visited[curr]) {
                visited[curr] = 1;
                for (int j = 0; j < isConnected.size(); j++) {
                    if (isConnected[curr][j] == 1 && !visited[j]) {
                        st.push(j);
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }
};
