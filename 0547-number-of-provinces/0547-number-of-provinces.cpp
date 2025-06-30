class Solution {
public:
    int findParent(int x, vector<int> &parent) {
        if (parent[x] != x)
            parent[x] = findParent(parent[x], parent); 
        return parent[x];
    }

    void unionSet(int v, int u, vector<int> &parent) {
        int parentV = findParent(v, parent);
        int parentU = findParent(u, parent);
        
        if (parentV != parentU) {
            parent[parentV] = parentU;
        }
    }

    vector<vector<int>> getComponents(vector<vector<int>> &matrix) {
        int V = matrix.size();
        vector<int> parent(V);
        for (int i = 0; i < V; i++) parent[i] = i;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][j] == 1 && i != j) {
                    unionSet(i, j, parent);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            parent[i] = findParent(i, parent);
        }

        unordered_map<int, vector<int>> resMap;
        for (int i = 0; i < V; i++) {
            resMap[parent[i]].push_back(i);
        }

        vector<vector<int>> res;
        for (auto &entry : resMap) {
            res.push_back(entry.second);
        }

        return res;
    }

    int findCircleNum(vector<vector<int>> &isConnected) {
        return getComponents(isConnected).size();
    }
};
