class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        // BRUTE FORCE
        vector<int> ans;
   
        for(auto &q: queries){
            int l=q[0];
            int r=q[1];
            int cnt=0;
            for(int j=l;j<=r;j++){
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
        
        
        // OPTIMAL SOLUTION
        int n=s.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                pre[i+1]=pre[i]+1;
            }
            else{
                pre[i+1]=pre[i];
            }
        }
        vector<int> ans;
        for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            ans.push_back(pre[r+1]-pre[l]);
        }
        return ans;
    }
};