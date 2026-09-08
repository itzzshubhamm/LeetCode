class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

         int n = grid.size();
        vector<vector<int>> minRequiredWaterLevel(n, vector<int>(n,INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;

        minRequiredWaterLevel[0][0] = grid[0][0];

        minHeap.push({minRequiredWaterLevel[0][0],0,0});

        int r[] = {-1,1,0,0};
        int c[] = {0,0,-1,1};

        while(!minHeap.empty()){

            auto[water, row, col] = minHeap.top();

            if(row == n-1 && col == n-1){
                return water;
            }

            minHeap.pop();
            for(int i=0; i<4; i++){
                int nr = row + r[i];
                int nc = col + c[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n){
                    continue;
                }

            int newWaterLevel = max(water,grid[nr][nc]);
            if(newWaterLevel<minRequiredWaterLevel[nr][nc]){
                minRequiredWaterLevel[nr][nc] = newWaterLevel;
                minHeap.push({newWaterLevel,nr,nc});
            }
            } 

        }

        return -1;

        
    }
};