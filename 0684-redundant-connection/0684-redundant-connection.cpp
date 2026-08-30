class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        parent[rootB] = rootA;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {

            int a = edge[0];
            int b = edge[1];

            if (find(a) == find(b)) {
                return {a, b};
            }

            unite(a, b);
        }

        return {};
    }
};