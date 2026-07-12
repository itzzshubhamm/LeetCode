class Solution {
public:

    vector<vector<int>> answerToReturn;

    void permuteHelper(vector<int>& nums , int index){

        if(index >= nums.size()){
            answerToReturn.push_back(nums);
            return;
        }

       for(int i=index ; i<nums.size() ; i++){
          swap(nums[index] , nums[i]);
          permuteHelper(nums , index+1);
          swap(nums[index] , nums[i]);
       }
            
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
       permuteHelper(nums , 0);
       return answerToReturn;
    }
};