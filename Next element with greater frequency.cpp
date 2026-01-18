class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> res(n,-1);
        // count frequency
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && mp[arr[i]]>mp[arr[st.top()]]){
                res[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
