void dfs(int node,  vector<int> &df, vector<int> adj[], int vis[]){
        vis[node] = 1;
        df.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, df, adj, vis);
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> df;
        dfs(0, df, adj, vis);
        return df;
    }