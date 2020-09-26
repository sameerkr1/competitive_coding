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
const ll BLK=1e3,N=1e6+5;
ll fre[N],cnt=0,a[N],b[N],k;
struct query{
   ll l,r,id;
};
query qq[N];
bool comp(query a,query b){
   if(a.l/BLK!=b.l/BLK)return a.l<b.l;
   return a.r<b.r;
}
void add(ll pos){
   fre[a[pos]]++;
   if(fre[a[pos]]==k)cnt++;
}
void rem(ll pos){
   if(fre[a[pos]]==k)cnt--;
   fre[a[pos]]--;
}
signed main(){
    FASTIO;
    ll tt=1;
    cin>>tt;
    while(tt--){
        ll n,q;cin>>n>>q>>k;
        cnt=0;
        memset(fre,0,sizeof(fre));
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<q;i++){
           cin>>qq[i].l>>qq[i].r;
           qq[i].l--;qq[i].r--;
           qq[i].id=i;
        }
        sort(qq,qq+q,comp);
        ll curl=0,curr=-1;
        for(ll i=0;i<q;i++){
            ll L=qq[i].l;
            ll R=qq[i].r;
            while(curl>L){
               curl--;
               add(curl);
            }
            while(curr<R){
               curr++;
               add(curr);
            }
            while(curr>R){
               rem(curr);
               curr--;
            }
            while(curl<L){
               rem(curl);
               curl++;
            }
            b[qq[i].id]=cnt;
        }
        for(ll i=0;i<q;i++)cout<<b[i]<<" ";
        cout<<"\n";
    }
}
