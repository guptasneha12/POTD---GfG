class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                char top=st.top();
                st.pop();
                bool redundant=true;
                while(!st.empty() && top!='('){
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        redundant=false;
                    }
                    top=st.top();
                    st.pop();
                }
                if(redundant==true){
                    return true;
                }
            }
            else {
                st.push(s[i]);
            }
        }
        return false;
    }
};
