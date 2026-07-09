class Solution {
public:
    vector<string> answer;

    void combinationOfParenthesis(int n , int open , int close , int index , string& curr){

        if(index == n*2){
            answer.push_back(curr);
            return;
        }
        if(open < n){
            curr += "(";
            combinationOfParenthesis(n , open+1 , close , index+1  ,curr);
            curr.pop_back();
        }
        if(close < open){
            curr += ")";
            combinationOfParenthesis(n , open , close+1 , index+1 , curr);
            curr.pop_back();
        }
    };


    vector<string> generateParenthesis(int n) {
        string curr;
        combinationOfParenthesis(n , 0 , 0 , 0 , curr);
        return answer;
    };
};