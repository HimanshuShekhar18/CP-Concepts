// Template for Binary Lifting 


int x=log(n)+1; //max possible jump req to reach a parent (You can also take x=30)

vector<vector<int> > v; // adjacency list of tree
int par[n][x]; 
// par[i][j] = 2^(j)th parent of ith node

void dfs(int s,int p)
{
// s-->source node
// p-->parent of s..
 par[s][0]=p;
 for(int j=1;j<=x;j++)
  par[s][j]=par[par[s][j-1]][j-1];
for(int i=0;i<v[s].size();i++)
{
   int ch=v[s][i];
   if(ch!=p)
    dfs(ch,s)
}
}

// k-->jump-->binary representation

int find_kth (int s, int k)
{
 for (int j=x; j>=0; j--)
 {
   if((1<<j)&k)//jth bit set or not in k..
{
  s=par[s][j] ;//jump of 2^j
  k-=(1<<j);
}
return s;


