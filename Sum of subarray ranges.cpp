class Solution {
  public:
    int subarrayRanges(vector<int>& nums) {
        // code here
        //BRUTE FORCE APPROACH
        // int sum=0;
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     int mini=arr[i];
        //     int maxi=arr[i];
        //     for(int j=i;j<n;j++){
        //         if(arr[j]>maxi){
        //             maxi=arr[j];
        //         }
        //         if(arr[j]<mini){
        //             mini=arr[j];
        //         }
        //         sum+=(maxi-mini);
        //     }
        // }
        // return sum;
        
        
        // OPTIMISED APPROACH
     int n = nums.size();
        vector<int> ple(n), nle(n), pge(n), nge(n);
        stack<int> st;

        // Previous Less Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Less Element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Greater Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Greater Element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0, maxSum = 0;

        for(int i = 0; i < n; i++) {
            long long leftMin = i - ple[i];
            long long rightMin = nle[i] - i;
            minSum += nums[i] * leftMin * rightMin;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxSum += nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
        
    }
};