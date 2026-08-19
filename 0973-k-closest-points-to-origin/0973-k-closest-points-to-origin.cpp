class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto val : points) {
            int x = val[0];
            int y = val[1];

            int distance = (x * x) + (y * y);
            pq.push({distance, {x, y}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (pq.size() > 0) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};