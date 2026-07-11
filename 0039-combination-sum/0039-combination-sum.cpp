class Solution {
public:

    vector<vector<int>> answerToReturn;

    void combinationHelper(vector<int>& candidates , int target , vector<int>& currentArray , int index ){

        if(target == 0){
            answerToReturn.push_back(currentArray);
            return;
        }
        if(target < 0){
            return;
        }
        if(index >= candidates.size()){
            return;
        }

        if(candidates[index] <= target){
        currentArray.push_back(candidates[index]);
        combinationHelper(candidates , target - candidates[index] , currentArray , index);
        currentArray.pop_back();
        }
        combinationHelper(candidates , target , currentArray , index+1);
       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentArray;
        combinationHelper(candidates , target , currentArray , 0);
        return answerToReturn;
    }
};