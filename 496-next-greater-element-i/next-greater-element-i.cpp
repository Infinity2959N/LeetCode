class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nextGreater;

        for(int i=nums2.size()-1; i>=0; i--){
            int num=nums2[i];
            while(!st.empty() && num > st.top()){
                st.pop();
            }
 
            if(!st.empty()){ 
                nextGreater[num]=st.top();
            }
            else nextGreater[num]=-1;

            st.push(num);
        }

        for(int i=0; i< nums1.size(); i++){
            nums1[i]=nextGreater[nums1[i]];
        }
        return nums1;
    }
};