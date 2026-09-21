class Solution {
public:
    vector<bool> visited;
    vector<int> dt;
    vector<int> lt;
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int u, int parent) {
        visited[u] = true;
        dt[u] = lt[u] = timer++;

        for (auto& neighbour : adj[u]) {
            if (!visited[neighbour]) {
                dfs(neighbour, u);
                lt[u] = min(lt[u], lt[neighbour]);

                if (lt[neighbour] > dt[u]) {
                    ans.push_back({u, neighbour});
                }
            } else if (neighbour != parent) {
                lt[u] = min(lt[u], dt[neighbour]);
            } else {
                continue;
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        visited = vector<bool>(n, false);
        dt = vector<int>(n);
        lt = vector<int>(n);
        adj = vector<vector<int>>(n);
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        return ans;
    }
};