class Solution {
  public:
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        auto first=bfs(adj,1);
        int farnode=first.first;
        // find diameter
        auto second=bfs(adj,farnode);
        int diam=second.second;
        return (diam+1)/2;
    }
    private:
    pair<int,int> bfs(vector<vector<int>> &adj, int start){
        int n=adj.size();
        vector<int> dist(n+1,-1);
        queue<int> q;
        q.push(start);
        dist[start]=0;
        int farnode=start;
        int fardis=0;
        // use bfs
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int next:adj[node-1]){
                if(dist[next]==-1){
                    dist[next]=dist[node]+1;
                    q.push(next);
                    if(dist[next]>fardis){
                        fardis=dist[next];
                        farnode=next;
                    }
            }
        }
    }
    return {farnode,fardis};
    }
};