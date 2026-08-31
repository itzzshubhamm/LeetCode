class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)){
            return 0;
        }
           
        queue<string> q;

        q.push(beginWord);
        int num=1;

        while(!q.empty()){
            int size=q.size();

            while(size--){
            string currWord = q.front();
            if(currWord == endWord){
              return num;
            }
            q.pop();

            for(int i=0; i<currWord.size(); i++){
                char curChar = currWord[i];
               for(char ch='a'; ch<='z'; ch++){
                  currWord[i] = ch;
                  if(st.count(currWord)){
                    q.push(currWord);
                    st.erase(currWord);
                  }
               }
               currWord[i]=curChar;
            }
            }

            num++;

        }
        return 0;
        
    }
};