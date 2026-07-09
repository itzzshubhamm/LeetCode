class Solution {
public:

     vector<vector<int>> answer;
   
     void subsetsCreator(vector<int>& nums , vector<int>& curr , int index){

        if(index == nums.size()){
            answer.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        subsetsCreator(nums , curr , index+1);
        curr.pop_back();
        subsetsCreator(nums , curr , index+1);
     }


    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> curr;
        subsetsCreator(nums , curr , 0);

        return answer;
        
    }
};