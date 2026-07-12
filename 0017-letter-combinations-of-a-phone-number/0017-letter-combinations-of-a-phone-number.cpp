class Solution {
public:
    vector<string> answerToReturn;
    vector<string> keypad = {
    "",      // 0
    "",      // 1
    "abc",   // 2
    "def",   // 3
    "ghi",   // 4
    "jkl",   // 5
    "mno",   // 6
    "pqrs",  // 7
    "tuv",   // 8
    "wxyz"   // 9
    };

    void letterCombinationHelper(string& digits , string& curr , int index){

        if(index == digits.size()){
            answerToReturn.push_back(curr);
            return;
        }  

        int indexForKey = digits[index] - '0';
        string mappedString = keypad[indexForKey];

        for(char ch : mappedString){     
            curr += ch;
            letterCombinationHelper(digits, curr, index+1);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {

    if (digits.empty())return {};

    string current;
    letterCombinationHelper(digits, current, 0);

    return answerToReturn;
        
    }
};