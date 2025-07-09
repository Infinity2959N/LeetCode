class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= beginWord.size();
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);

        // Edge case: endWord not in the list:
        if(!dict.count(endWord))    return 0;

        int count=1;    //count 1 as beginWord is the first word
        while(!q.empty()){
            int currSize= q.size();
            while(currSize--){
                string word= q.front();
                if(word== endWord)  return count;
                q.pop();
                
                for(int i=0; i<n; i++){
                    string newWord= word;
                    for(int letter= 0; letter< 26; letter++){
                        if(newWord[i]!= 'a'+letter)    newWord[i]= 'a'+letter;
                        if(dict.count(newWord)){
                            q.push(newWord);
                            dict.erase(newWord);
                        }
                    }
                }
            }
            count++;    // Increment step after one full level
        }
        return 0;
    }
};