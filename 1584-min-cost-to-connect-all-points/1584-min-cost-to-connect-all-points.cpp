class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        vector<bool> mst(n,false);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        int totalCost=0;
        int vertexTaken=0;
        
        q.push({0,0});

        while(!q.empty() && vertexTaken < n){
            auto[cost, index] = q.top();
            q.pop();

            if(mst[index]){
                continue;
            }

            mst[index]=true;
            vertexTaken++;
            totalCost += cost;

            for(int i=0; i<n; i++){
                if(mst[i]){
                    continue;
                }

                int x1 = points[index][0];
                int y1 = points[index][1];
                int x2 = points[i][0];
                int y2 = points[i][1];

                int tempCost = abs(x1 - x2) + abs(y1-y2);

                q.push({tempCost,i});

            }

        }

        return totalCost;




        
    }
};