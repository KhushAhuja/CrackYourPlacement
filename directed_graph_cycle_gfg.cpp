bool dfs(int node, vector<int> adj[], int vis[], vector<int>& stack){
        stack[node]=1;
        vis[node]=1;
        for(auto it: adj[node]){
            if(stack[it]) return true;
            if(!vis[it] and dfs(it, adj, vis, stack)) return true;
        }
        stack[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        vector<int> stack(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i] and dfs(i, adj, vis, stack)) return true;
        }
        return false;
    }