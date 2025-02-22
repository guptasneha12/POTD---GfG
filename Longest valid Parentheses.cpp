class Solution {
  public:
    int maxLength(string& s) {
        int n=s.size();
        stack<int> st;
        int maxi=0;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                maxi=max(maxi,i-st.top());
            }
        }
        return maxi;
    }
};