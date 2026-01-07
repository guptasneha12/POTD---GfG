class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<int> res;
        // for f1st 4 elements
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        res.push_back(mp.size());
        // for remaining n-k elements
        for(int i=k;i<n;i++){
            int ele=arr[i-k];
            mp[ele]--;
            if(mp[ele]==0) mp.erase(ele);
            mp[arr[i]]++;
            res.push_back(mp.size());
        }
        return res;
    }
};
