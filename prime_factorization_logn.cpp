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
const ll N=1e6+5;
ll prime[N];
void is_prime(){
   for(ll i=2;i<=N;i+=2)prime[i]=2;
   for(ll i=3;i<=N;i+=2){
      if(!prime[i]){
         for(ll j=i;j<=N;j+=i){
            if(!prime[j])prime[j]=i;
         }
      }
   }
}
signed main(){
    FASTIO;
    ll tt=1;
    cin>>tt;
    is_prime();
    while(tt--){
       ll n;cin>>n;
       for(ll i=2;i<20;i++)cout<<i<<" "<<prime[i]<<"\n";
    }
}
