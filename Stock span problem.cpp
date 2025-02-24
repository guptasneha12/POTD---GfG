class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        stack<pair<int,int>> st;
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int ele=arr[i];
            int cnt=1;
            while(!st.empty() && st.top().first<=ele){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            ans[i]=cnt;
        }
        return ans;
        
    }
};