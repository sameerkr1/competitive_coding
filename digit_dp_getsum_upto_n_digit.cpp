#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e11
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
const ll N=1e5+3;
ll getsum(ll pos,ll n,ll sum){
   if(pos>n)return sum;
   ll res=0;
   for(ll i=0;i<=9;i++){
      res+=getsum(pos+1,n,sum+i);
   }
   return res;
}
signed main(){
    FASTIO;
    ll tt=1;
    cin>>tt;
    while(tt--){
       ll n;cin>>n;
       cout<<getsum(1,n,0)<<"\n";
    }
}
