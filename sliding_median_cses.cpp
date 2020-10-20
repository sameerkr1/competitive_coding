#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
const ll N=17;

signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
        ordered_set st;
        ll n,k;cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
           cin>>a[i];
        }
        ll ans=0;
        for(ll i=0;i<k;i++)st.insert(a[i]);
        ll old_m=*st.find_by_order((k-1)/2);
        for(ll i=0;i<k;i++){
           ans+=abs(a[i]-old_m);
        }
        cout<<ans<<" ";
        for(ll i=k;i<n;i++){
           st.erase(st.upper_bound(a[i-k]));
           st.insert(a[i]);
           ll m=*st.find_by_order((k-1)/2);
           ans+=-abs(old_m-a[i-k])+abs(m-a[i]);
           if(k%2==0)ans-=m-old_m;
           cout<<ans<<" ";
           old_m=m;
        }
    }
}
