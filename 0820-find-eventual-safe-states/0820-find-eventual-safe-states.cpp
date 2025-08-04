class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                revgraph[neighbor].push_back(i);
                inDegree[i]++;
            }
        }

    
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (int neighbor : revgraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
