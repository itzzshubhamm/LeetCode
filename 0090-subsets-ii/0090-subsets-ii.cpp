class Solution {
public:

    vector<vector<int>> answerToReturn;
    
    void subsetHelper(vector<int>& nums , int index , vector<int>& currentArray){

        if(index >= nums.size()){
            answerToReturn.push_back(currentArray);
            return;
        }

        currentArray.push_back(nums[index]);
        subsetHelper(nums , index + 1 , currentArray);
        currentArray.pop_back();

        while(index+1 < nums.size() && nums[index+1] == nums[index] ){
            index++;
        }
        subsetHelper(nums , index + 1 , currentArray);
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> currentArray;
        sort(nums.begin() , nums.end());
        subsetHelper(nums , 0 , currentArray);

        return answerToReturn;
    }
};