class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int res=0;
        // use unordered map to store the unique count of each ele
        unordered_map<int,int> freq;
        int left=0,right=0;
        while(right<n){
            freq[arr[right]]+=1;
            // if it is 1st element
            if(freq[arr[right]]==1) k--;
            while(k<0){
                freq[arr[left]]--;
                if(freq[arr[left]]==0) k++;
                left++;
            }
            res+=(right-left+1);
            right++;
        }
        return res;
    }
};