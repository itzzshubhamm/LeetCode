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
            string currentWord = q.front();
            if(currentWord == endWord){
              return num;
            }
            q.pop();

            for(int i=0; i<currentWord.size(); i++){
                char currentChar = currentWord[i];
               for(char ch='a'; ch<='z'; ch++){
                  currentWord[i] = ch;
                  if(st.count(currentWord)){
                    q.push(currentWord);
                    st.erase(currentWord);
                  }
               }
               currentWord[i]=currentChar;
            }
            }

            num++;

        }
        return 0;
        
    }
};