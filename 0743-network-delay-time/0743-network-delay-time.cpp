class Solution {
public:
    const int INF = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> graph(n+1);
        vector<int> timeAns(n+1,INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
      
       for(auto& time : times){
        int u = time[0];
        int v = time[1];
        int w = time[2];
        graph[u].push_back({v,w});
       }

       timeAns[k] = 0;

       q.push({0,k});

       while(!q.empty()){

        auto [time, nodeVal] = q.top();
        q.pop();

        if(time > timeAns[nodeVal]){
            continue;
        }

        for(auto& neighbour : graph[nodeVal]){
            auto [next , takingTime] = neighbour;
            int newTime = time + takingTime;

            if(newTime < timeAns[next]){
                timeAns[next] = newTime;
                q.push({newTime,next});
            }
        }

       }

       int maxValue = *max_element(timeAns.begin() + 1, timeAns.end());

       if(maxValue == INF){
        return -1;
       }

       return maxValue;



        
    }
};