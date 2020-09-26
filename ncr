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
#define MOD 998244353
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
const ll N=3e5+5;
ll fac[N];
void factorial(){
   fac[0]=1;
   for(ll i=1;i<N;i++){
      fac[i]=(fac[i-1]%MOD*i%MOD)%MOD;
   }
}
ll power(ll a,ll b){
   ll res=1;
   while(b){
      if(b&1)res=(res%MOD*a%MOD)%MOD;
      b>>=1;
      a=(a%MOD*a%MOD)%MOD;
   }
   return res;
}
ll inverse(ll n){
    return power(n,MOD-2);
}
ll ncr(ll n,ll r){
   return (fac[n]%MOD*inverse((fac[n-r]%MOD*fac[r]%MOD)%MOD)%MOD)%MOD;
}
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       vector<pii>vv(n);
       vector<ll>a(n);
       for(ll i=0;i<n;i++){
          cin>>vv[i].ss>>vv[i].ff;
          a[i]=vv[i].ss;
       }
       sort(all(vv));
       sort(all(a));
       factorial();
       ll ans=0;
       for(ll i=0;i<n;i++){
          auto it=upper_bound(all(a),vv[i].ff);
          it--;
          ll ele=it-a.begin()-i+1;
          if(ele<k)continue;
          ans=(ans%MOD+ncr(ele-1,k-1)%MOD)%MOD;
       }
       cout<<ans<<"\n";
    }
}
