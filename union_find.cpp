#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e9
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define pb push_back
#define all(s) s.begin(),s.end()
#define pie 3.14159265358979323846
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define gcd __gcd
#define con continue
#define pii pair<ll,ll>
const ll N=1e5+6;
ll n,a,b,x;
ll par[N];
void make_par(){
   for(ll i=0;i<N;i++)par[i]=i;
}
ll find_par(ll u){
   if(par[u]==u)return u;
   return par[u]=find_par(par[u]);
}
void union_par(ll a,ll b){
   a=find_par(a);
   b=find_par(b);
   par[a]=b;
   return;
}
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
         make_par();
         ll n,m;cin>>m>>n;
         for(ll i=0;i<n;i++){
            cin>>x;
            if(x==1){
               cin>>a>>b;
               a=find_par(a);
               b=find_par(b);
               if(a==b)cout<<"1\n";
               else cout<<"0\n";
               con;
            }
            cin>>a>>b;
            union_par(a,b);
         }
    }
}
