class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans;
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                // if sum is present in map
                if(mp.count(sum)){
                    auto it=mp[sum];
                    int a=it.first;
                    int b=it.second;
                    int c=i;
                    int d=j;
                    if(a!=i && a!=j && b!=i && b!=j){
                        vector<int> curr={a,b,c,d};
                        if(ans.empty() || ans>curr){
                            ans=curr;
                        }
                    }
                }
                // if sum is not present then add it into map
                else{
                    mp[sum]={i,j};
                }
            }
        }
        
        if(ans.empty()){
            return {-1,-1,-1,-1};
        }
        return ans;
    }
};