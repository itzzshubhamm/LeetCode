class Solution {
public:
    bool isValid(vector<int>& piles , int mid , int h){
         
        int currentTime=0; 
          
        for(int i=0 ; i<piles.size() ; i++){
           currentTime += ceil((double)piles[i]/mid);
           if(currentTime > h){
            return false;
           }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin() , piles.end());
        int answer;

        while(minSpeed <= maxSpeed){
            int mid = minSpeed + (maxSpeed - minSpeed)/2;

            if(isValid(piles , mid , h)){
              answer = mid;
              maxSpeed = mid-1;
            }
            else{
                minSpeed = mid + 1 ;
            }
        }

        return answer;

    }
};