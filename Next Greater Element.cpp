class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(arr[n-1]);
        for(int i=n-1;i>=0;i--){
            int ele=arr[i];
            while(!st.empty() && st.top()<=ele){
                st.pop();
            }
           if(!st.empty()){
                ans[i]=st.top();
           }
            st.push(ele);
            
        }
        
        return ans;
    
    }
};