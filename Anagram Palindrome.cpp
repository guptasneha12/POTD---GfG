class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int even=0;
        int odd=0;
        for(auto &it: mp){
            if(it.second%2==0){
                even++;
            }
            else if(it.second%2!=0){
                odd++;
            }
        }
        if(odd>1) return false;
        else return true;
    }
};