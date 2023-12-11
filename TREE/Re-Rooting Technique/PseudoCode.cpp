void dfs2(int node, int par)
{
 int t1=dp[node];
  for(auto it: adj[node])
  {
     if(it==par)
        continue;
    int t2=dp[it];
   // transfer root from node to it

    dfs(it,node);
    // rollback root to node
    // (restore old values)   
   dp[node]=t1;
   dp[it]=t2;
 
  }
}
