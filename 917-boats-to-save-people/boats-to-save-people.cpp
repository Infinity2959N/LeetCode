class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n= people.size();
        // impossible:
        if(people[n-1]> limit) return -1;
        // Two cases: Either the last person is the only one the boat can carry, or we throw in pairs from first and last
        int left=0, right= n-1, count=0;
        while(left<=right){
            if(people[right]+people[left]> limit){
                count++; right--;
            }else{
                left++; right--; count++;
            }
        }
        return count;
    }
};