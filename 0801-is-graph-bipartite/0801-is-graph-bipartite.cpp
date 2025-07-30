class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int src, int color, vector<int>& cl) {
        cl[src] = color;
        for (int i = 0; i < graph[src].size(); i++) {
            int neighbor = graph[src][i];
            if (cl[neighbor] == -1) {
                if (!dfs(graph, neighbor, 1 - color, cl))
                    return false;
            } else if (cl[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (colors[i] == -1) {
                if (!dfs(graph, i, 0, colors))
                    return false;
            }
        }
        return true;
    }
};
