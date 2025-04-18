class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty())  return 0;
        int s1=g.size(), s2=s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0, j=0;
        while(i< s1 && j< s2){
            if(s[j++]>= g[i]){
                i++;
            }
        }
        return i;
    }
};