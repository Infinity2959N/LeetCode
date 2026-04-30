// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // binary search on answer
        // If curr isbad, it's a candidate and move the right to previous
        // If curr is not bad, move left to mid+1;
        int left=1, right=n, candidate=0;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(isBadVersion(mid)){
                //quick call to break sooner
                if(!isBadVersion(mid-1)) return mid;
                candidate=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};