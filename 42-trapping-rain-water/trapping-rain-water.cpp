class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        // Build the leftMax array to store the leftTallest wall
        for(int i=1; i<n; i++){
            leftMax[i]= max(leftMax[i-1], height[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            rightMax[i]= max(rightMax[i+1], height[i+1]);
        }

        // Now find the actual water:
        int water=0;
        for(int i=1; i<n-1; i++){
            water+= max(0, min(leftMax[i], rightMax[i])- height[i]);
        }
        return water;
    }
};