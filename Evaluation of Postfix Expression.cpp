class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(string it:arr){
        
            if(isdigit(it[0]) || (it.size()>1 && it[0]=='-')){
                st.push(stoi(it));
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(it=="+"){
                    st.push(b+a);
                }else if(it=="-"){
                    st.push(b-a);
                }
                else if(it=="*"){
                    st.push(b*a);
                }
                else if(it=="/"){
                    st.push(b/a);
                }
            }
            
        }
        return st.top();
    }
};