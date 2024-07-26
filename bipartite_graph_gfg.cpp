void dfs(int node, int vis[], vector<int> adj[], vector<int>& color, int curColor){
        if(color[node]!=-1){
            if(color[node]!=curColor) bipart=false;
            return;
        } 
        color[node]=curColor;
        vis[node]=1;
        for(auto it:adj[node]){
            dfs(it, vis, adj, color, curColor ^ 1);
        }
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int vis[V]={0};
	    vector<int> color(V, -1);
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(i, vis, adj, color, 1);
	    }
	    return bipart;
	}