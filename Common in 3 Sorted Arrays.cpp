class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int n1=a.size(),n2=b.size(),n3=c.size();
        int i=0,j=0,k=0;
        vector<int> common;
        while(i<n1 && j<n2 && k<n3){
            if(a[i]==b[j] && b[j]==c[k]){
                common.push_back(a[i]);
                i++;
                j++;
                k++;
                
                // skip duplicate ele
                while(i<n1 && a[i]==a[i-1]) i++;
                while(j<n2 && b[j]==b[j-1]) j++;
                while(k<n3 && c[k]==c[k-1]) k++;
            }
            // else move the pointer of smallest ele
            else if(a[i]<b[j]) i++;
            else if(b[j]<c[k]) j++;
            else k++;
        }
        return common;
    }
};