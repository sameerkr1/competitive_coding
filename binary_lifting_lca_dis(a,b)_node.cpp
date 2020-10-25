#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e18
#define ff first
#define ss second
#define MOD 1000000007
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define pb push_back
#define all(s) s.begin(),s.end()
#define pie 3.14159265358979323846
#define fr(i,a,b)  for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define gcd __gcd
#define con continue
#define pii pair<ll,ll>
const ll N=2e5+5,MaxN=18;
ll par[N][MaxN],dis[N];
ll vis[N];
vector<ll>mm[N];

void dfs(ll src,ll p){
    par[src][0]=p;
    for(auto x:mm[src]){
       if(x!=p){
          dfs(x,src);
       }
    }
}
void bfs(ll src){
    queue<ll>qq;
    qq.push(src);
    vis[src]=1;
    while(!qq.empty()){
       ll ele=qq.front();
       qq.pop();
       for(auto x:mm[ele]){
          if(!vis[x]){
             qq.push(x);
             dis[x]=dis[ele]+1;
             vis[x]=1;
          }
       }
    }return;
}
void init(){

    for(ll j=0;j<MaxN;j++){
       for(ll i=0;i<N;i++)par[i][j]=-1;   // intializing with -1 to Maxn X N table
    }

    dfs(1,-1);
    bfs(1);    // for distance

    for(ll j=1;j<MaxN;j++){
       for(ll i=1;i<N;i++){
          if(par[i][j-1]!=-1){
             ll p=par[i][j-1];
             par[i][j]=par[p][j-1];
          }
       }
    }
}
ll lca(ll a,ll b){
    if(dis[a]>dis[b])return lca(b,a);
    ll d=dis[b]-dis[a];
    while(d){
       ll i=log2(d);
       d-=(1<<i);
       b=par[b][i];
    }
    if(a==b)return a;
    for(ll i=MaxN-1;i>=0;i--){
       if(par[a][i]!=-1&&par[a][i]!=par[b][i]){
          a=par[a][i];
          b=par[b][i];
       }
    }
    return par[a][0];
}
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
        ll n,q;cin>>n>>q;
        for(ll i=1;i<n;i++){
           ll a,b;cin>>a>>b;
           mm[a].pb(b);
           mm[b].pb(a);
        }
        init();
        while(q--){
           ll a,b,ans;cin>>a>>b;
           ans=dis[a]+dis[b]-2*dis[lca(a,b)];
           cout<<ans<<"\n";
        }
    }
}
