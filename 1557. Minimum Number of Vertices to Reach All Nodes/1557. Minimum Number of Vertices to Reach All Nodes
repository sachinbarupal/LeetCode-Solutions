class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> check(n,false);  vector<int> ans;
        
        for(auto &link  : edges)
            check[link[1]]  = true;
            
        for(int i=0;i<n;++i)
        {
            if(check[i]==false) ans.push_back(i);
        }
        
        return ans;
    }
};
