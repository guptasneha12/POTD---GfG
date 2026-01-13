class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n=arr.size();
        int five=0,ten=0;
        for(int i=0;i<n;i++){
            // for 5
            if(arr[i]==5){
                five++;
            }
            // for 10
            else if(arr[i]==10){
                if(five>0){
                    ten++;
                    five--;
                }
                else return false;
            }
            // for 20
            else{
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};