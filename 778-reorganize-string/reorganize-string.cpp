class Solution {
public:
    string reorganizeString(string s) {
        // To return any possible arrangement of s
        // Pattern: Interleave or Schedule based on frequency-> MaxHeap
        // Bottleneck: Not the rare characters, but the most frequent characters. If 'a' comes 5 times and 'b' 2 times, need to spend those 'a's as fast as possible by buffering them with other characters.
        // Read notes

        priority_queue<pair<int, char>> pq;    // Default is max heap on first element
        int counts[26]={0};
        for(char c: s){
            counts[c-'a']++;
        }

        for(int i=0; i<26; i++){
            if(counts[i]>0){
                // Pigeonhole:
                if(counts[i]> (s.length()+1)/2) return "";
                pq.push({counts[i], (char)(i+'a')});
            }
        }

        string res="";

        while(pq.size()>=2){
            auto [f1, c1]= pq.top(); pq.pop();
            auto [f2, c2]= pq.top(); pq.pop();
            
            res+=c1; res+= c2;

            if(--f1>0) pq.push({f1, c1});
            if(--f2>0) pq.push({f2, c2});
        }

        if(!pq.empty()){
            res+= pq.top().second;
        }

        return res;
    }
};