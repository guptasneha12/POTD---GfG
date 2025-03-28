class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        // pair to store start and end time
        int n=start.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({start[i],finish[i]});
        }
        // comparator operator to arrange in ascending order or finish time
        auto comp=[&](auto& a,auto& b){
            return a.second<b.second;
        };
        sort(temp.begin(),temp.end(),comp);
        int cnt=1;
        int currfinish=temp[0].second;
        for(int i=1;i<n;i++){
            if(temp[i].first>currfinish){
                cnt++;
                currfinish=temp[i].second;
            }
        }
        return cnt;
        
    }
};