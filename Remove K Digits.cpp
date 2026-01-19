class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n=s.size();
        stack<char> st;
        string ans="";
        for(int i=0;i<n;i++){
            char c=s[i];
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            if(!st.empty() || c!='0'){
                st.push(c);
            }
        }
        
        // remove remaining 
        while(!st.empty() && k--) st.pop();
        if(st.empty()) return "0";
        // store ans 
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};