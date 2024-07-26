bool dfs(int node, vector<int> adj[], int vis[], int par){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it] and it!=par) return true;
            if(it!=par and dfs(it,adj, vis, node)) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i] and dfs(i,adj, vis, -1)){
                return true;
            } 
        }
        return false;
    }