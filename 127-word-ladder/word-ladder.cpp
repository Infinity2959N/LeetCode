class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Think BFS
        // Reach from beginword to endword, treat each character as a node in graph, move to next nodes.
        // For each word in BFS queue, we change every index to all possible characters (a-z) and see if that new word exists in the map (to be initialized with wordlist prior), if yes we push that word on the stack

        unordered_set<string> words;
        for(string word: wordList) words.insert(word);
        if(!words.count(endWord)) return 0;

        queue<string> bfs;
        bfs.push(beginWord);
        int steps=0;
        while(!bfs.empty()){
            steps++;
            int s= bfs.size();
            for(int x=0; x<s; x++){
                string word= bfs.front(); bfs.pop();
                for(int i=0; i<word.size(); i++){
                    int curr=word[i]-'a';
                    string newWord= word;
                    for(int j=0; j<26; j++){
                        if(j==curr) continue;
                        newWord[i]= (char)j+'a';
                        if(newWord==endWord) return steps+1;
                        if(words.count(newWord)){
                            bfs.push(newWord);
                            words.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0; 
    }
};