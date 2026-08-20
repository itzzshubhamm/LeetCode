class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);
        queue<pair<char,int>> q;
        priority_queue<pair<int,char>> maxHeap;

        for(char val:tasks){
            int mapChar = val - 'A';
            freq[mapChar]++;
        }

        for(int i=0; i<26; i++){
             if(freq[i]>0){
                maxHeap.push({ freq[i], 'A'+i});
             }
        }
        int time=0;

        while(!maxHeap.empty() || !q.empty()){
          time++;
          if(!q.empty() && q.front().second == time){
             char task = q.front().first;
             q.pop();
             maxHeap.push({ freq[task - 'A'], task});
          }

          if(!maxHeap.empty()){
            char currTask = maxHeap.top().second;
            maxHeap.pop();
            freq[currTask - 'A']--;
            if(freq[currTask - 'A'] > 0){
               q.push({currTask , time + n + 1});
            }
          }
        }

        return time;
    }
};