class Solution {
public:
    void dfs(string &s,string &d,unordered_map<string,vector<pair<string,double>>> &adj,unordered_map<string,int> &vis,double &ans,double temp)
    {
        if(vis.find(s)!=vis.end()) return;

        if(s==d)
        {
            ans = temp; return;
        }
        vis[s]=1;

        for(auto &child : adj[s])
        {
            string childNode = child.first;
            double val = child.second;

            dfs(childNode,d,adj,vis,ans,temp*val);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n = values.size();
        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i=0;i<n;++i)
        {
            string a = equations[i][0],b=equations[i][1];
            double val = values[i];

            adj[a].push_back({b,val});
            adj[b].push_back({a,1.0/val});
        }

        vector<double> res;
        for(auto &query: queries)
        {
            string source = query[0],dest = query[1];
            unordered_map<string,int> vis;
            
            double ans = -1.0,temp=1.0;

            if(adj.find(source)!=adj.end())
                dfs(source,dest,adj,vis,ans,temp);

            res.push_back(ans);
        }
        return res;
    }
};
