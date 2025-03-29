class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int curr=0,points=0;
        vector<pair<int,int>> v;
        for(int i=0;i<deadline.size();i++){
            v.push_back({deadline[i],profit[i]});
        }
        int n=v.size();
        sort(v.begin(),v.end());
        // min - heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            if(v[i].first>curr){
                curr++;
                points+=v[i].second;
                pq.push(v[i].second);
                
            }
            else if(pq.top()<v[i].second){
                points-=pq.top();
                pq.pop();
                points+=v[i].second;
                pq.push(v[i].second);
            }
        }
        return {curr,points};
        
    }
};