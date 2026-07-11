class Solution {
public:

   vector<vector<int>> answerToReturn;


   void combinationHelper(vector<int>& candidates , int target , int index , vector<int>& currentArray){
       
       if(target == 0){
        answerToReturn.push_back(currentArray);
        return;
       }
       if(target <= 0){
        return;
       }
       if(index >= candidates.size()){
        return;
       }

       if(candidates[index] <= target){
       currentArray.push_back(candidates[index]);
       combinationHelper(candidates , target - candidates[index] , index + 1 , currentArray);
       currentArray.pop_back();
       }

       while(index+1 < candidates.size() && candidates[index+1] == candidates[index]){
       index++;
       }
       combinationHelper(candidates , target , index + 1 , currentArray);
   }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> currentArray;

        sort(candidates.begin() , candidates.end());

        combinationHelper(candidates , target , 0 , currentArray);
        return answerToReturn;
        
    }
};