class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Find the longest contiguous subarray that has exactly 2 distinct elements
        unordered_map<int, int> picked;

        int maxFruits= 0, currFruits=0;

        int counts=0;
        int left=0, right= 0;

        while(right< fruits.size()){  
            if(!picked[fruits[right]]){
                counts++;
                picked[fruits[right]]=1;    
                currFruits++;
            }

            else{
                picked[fruits[right]]++;
                currFruits++;
            }
            while(counts>2){
                currFruits--;
                picked[fruits[left]]--;
                if(picked[fruits[left++]]==0) counts--;
            }
            maxFruits= max(maxFruits, currFruits);
            right++;
        }
        return maxFruits; 
    }
};