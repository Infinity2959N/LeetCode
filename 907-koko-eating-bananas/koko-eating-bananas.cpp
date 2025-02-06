class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //helper fuinction to calculate the time:
        auto time=[&](int k){   //lambda function
            long long hours=0;
            for(int pile: piles){
                hours+= (pile+ k-1)/k;  //returns the ceil of pile/k
            }
            return hours;
        };
        
        int beg= 1, end= *max_element(piles.begin(), piles.end());

        while(beg<=end){
            int mid= beg+ (end-beg)/2;
            if(time(mid)<=h){
                end=mid-1;  //try a slower speed
            }else{
                beg=mid+1;
            }
        }
        return beg;
    }
};