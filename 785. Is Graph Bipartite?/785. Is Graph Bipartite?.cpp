class Solution {
public:
    bool check = true;
    void dfs(unordered_map<int,vector<int>> &adj,int node,vector<int> &col,int cl){

        if(col[node]!=-1){
            if(col[node]!=cl) check= false;
            else check = true;
            return;
        }

        col[node] = cl;

        for(auto &child : adj[node]){
            if(cl==0)
               dfs(adj,child,col,1);
            else
                dfs(adj,child,col,0);

            if(check==false) return;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;++i){
            for(auto &x: graph[i]){
                adj[i].push_back(x);
            }
        }
        
        for(int i=0;i<n;++i){
            if(col[i]==-1){
                dfs(adj,i,col,0);
                if(check==false) return false;
            }
        }
        return true;
    }
};
