class Solution {
public:
    using ll = long long;

    ll dijkstra(
        int n,
        vector<vector<int>>& edges,
        int source,
        int destination
    ) {
        vector<vector<pair<int, ll>>> graph(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ll w = edge[2];

            if (w == -1)
                continue;

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        const ll INF = 4e18;

        vector<ll> dist(n, INF);

        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currentDistance, u] = pq.top();
            pq.pop();

            if (currentDistance != dist[u])
                continue;

            for (auto [v, weight] : graph[u]) {

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;

                    pq.push({
                        dist[v],
                        v
                    });
                }
            }
        }

        return dist[destination];
    }


    vector<vector<int>> modifiedGraphEdges(
        int n,
        vector<vector<int>>& edges,
        int source,
        int destination,
        int target
    ) {

        const int BIG = 2000000000;

        ll fixedShortest =
            dijkstra(n, edges, source, destination);



        if (fixedShortest < target) {
            return {};
        }


        if (fixedShortest == target) {


            for (auto &edge : edges) {
                if (edge[2] == -1) {
                    edge[2] = BIG;
                }
            }

            return edges;
        }



        for (int i = 0; i < edges.size(); i++) {

            if (edges[i][2] != -1)
                continue;


            edges[i][2] = 1;


   
            ll currentShortest =
                dijkstra(
                    n,
                    edges,
                    source,
                    destination
                );



            if (currentShortest <= target) {

                

                edges[i][2] +=
                    target - currentShortest;


                for (int j = i + 1;
                     j < edges.size();
                     j++) {

                    if (edges[j][2] == -1) {
                        edges[j][2] = BIG;
                    }
                }

                return edges;
            }
        }
        return {};
    }
};