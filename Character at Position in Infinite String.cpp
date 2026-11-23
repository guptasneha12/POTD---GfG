class Solution {
  public:
    char posInfinite(string &s, int pos) {
        // code here
        long long len=s.size();
        long long step=1;  // for $ sign addition
        while(len<pos){
            len=2*len+step;
            step++;
        }
        while(step>1){
            step--; // no need of extra $ sign get added by first step
            long long prevlen=(len-step)/2;  // /2 beacuse of reverse string also get added
            if(pos<=prevlen){
                
            }
            // if pos lies in $ btw
            else if(pos<=(prevlen+step)){
                return '$';
            }
            // else if pos lies in rev range
            else{
                long long r=pos-(prevlen+step);
                pos=prevlen-r+1;  // finding index of pos char in original string
            }
            len=prevlen;
        }
        return s[pos-1];
    
    }
};