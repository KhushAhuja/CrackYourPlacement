vector<int> size;
    vector<int> par;
    vector<pair<int,pair<int,int>>> edges;
    
    int findUPar(int node){
        if(node==par[node]) return node;
        return par[node]=findUPar(par[node]);
    }
    
    void UnionBySize(int u, int v){
        int uup=findUPar(u);
        int vup=findUPar(v);
        if(size[uup]<size[vup]){
            par[uup]=vup;
            size[vup]+=size[uup];
        }
        else{
            par[vup]=uup;
            size[uup]+=size[vup];
        }
    }
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        size.resize(V,1);
        par.resize(V);
        for(int i=0;i<V;i++){
            par[i]=i;
        }
        int ans=0;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int w=it[1];
                edges.push_back({w,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        for(auto i:edges){
            int w=i.first;
            int u=i.second.first;
            int v=i.second.second;
            if(findUPar(u)!=findUPar(v)){
                ans+=w;
                UnionBySize(u,v);
            }
        }
        return ans;