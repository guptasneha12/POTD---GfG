class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for(auto it:s){
            char ch=it;
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(it);
            }else{
                if(st.empty()) return false;
                char c=st.top();
                st.pop();
                if((ch==')'&& c!='(') || (ch==']'&& c!='[') || (ch=='}' && c!='{')) return false;
                
            }
      
            
        }
              return st.empty();
    }
};