class Solution {
  public:
    string URLify(string &s) {
        // code here
        int n=s.size();
        string ans="";
        for(char c:s){
            if(c!=' '){
                ans+=c;
            }
            else{
                ans+="%20";
            }
        }
        return ans;
    }
};