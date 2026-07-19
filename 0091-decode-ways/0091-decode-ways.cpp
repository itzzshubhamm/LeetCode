class Solution {
public:

    int ways(string& s ){
        int n = s.size();

        int next2=1;
        int next1 = s[n-1] == '0' ? 0 : 1;
        int answer = 0;

        for(int i = n-2 ; i >= 0 ; i--){

            if(s[i] == '0'){
               answer = 0;
            }else{
            answer = next1;

            int num = ((s[i] - '0')*10) + (s[i+1] - '0');
            if(num >= 10 && num <= 26){
                answer += next2;
            }
            }

            next2 = next1;
            next1 = answer;
        }

        return answer;

    }


    int numDecodings(string s) {


        if(s.size() == 0){
            return 0;
        }
        if(s.size() == 1){
            if(s[0]== '0'){
                return 0;
            }
            else return 1;
        }

        return ways(s);
 
    }
};