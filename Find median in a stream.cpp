class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // use two priority queue
        
        // max heap to store left half smaller elements
        priority_queue<double> s;
        
        // min heap to store right larger elements
        priority_queue<double,vector<double>,greater<double>> g;
        
        double mid=arr[0];
        s.push(arr[0]);
        vector<double> ans;
        ans.push_back(mid);
        
        for(int i=1;i<arr.size();i++){
            int x=arr[i];
            if(s.size()>g.size()){
                if(x<mid){
                    g.push(s.top());
                    s.pop();
                    s.push(x);
                }else{
                    g.push(x);
                }
                mid=(s.top()+g.top())/2.0;
            }
            else if(s.size()==g.size()){
                if(x<mid){
                   s.push(x); 
                   mid=(double)s.top();
                }else{
                    g.push(x);
                    mid=(double)g.top();
                }
            }
            
            //  g.size()>s.size()
            else{
                if(x>mid){
                    s.push(g.top());
                    g.pop();
                    g.push(x);
                }else{
                    s.push(x);
                }
                mid=(s.top()+g.top())/2.0;
            }
            ans.push_back(mid);
        }
        return ans;
        
    }
};
