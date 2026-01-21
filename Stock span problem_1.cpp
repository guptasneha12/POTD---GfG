class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int currele=arr[i];
            int cnt=1;
            while(!st.empty() && st.top().first<=currele){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({currele,cnt});
            ans[i]=cnt;
        }
        return ans;
    }
};