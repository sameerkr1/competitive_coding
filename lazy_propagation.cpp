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
const ll N=2e5+4;
ll seg[4*N],lazy[4*N];
void build(ll s,ll e,ll idx,ll a[]){
    if(s==e){
        seg[idx]=a[s];return;
    }
    ll mid=(s+e)/2;
    build(s,mid,2*idx+1,a);
    build(mid+1,e,2*idx+2,a);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    return ;
}
ll query(ll s,ll e,ll idx,ll i,ll a[]){
    if(lazy[idx]!=0){
       ll ele=lazy[idx];
       seg[idx]+=(e-s+1)*ele;
       lazy[idx]=0;
       if(s!=e){
          lazy[2*idx+1]+=ele;
          lazy[2*idx+2]+=ele;
       }
    }
    if(s==e)return seg[idx];
    ll mid=(s+e)/2;
    if(mid>=i)return query(s,mid,2*idx+1,i,a);
    else return query(mid+1,e,2*idx+2,i,a);
}
void update(ll s,ll e,ll idx,ll l,ll r,ll a[],ll val){
    if(lazy[idx]!=0){
       ll ele=lazy[idx];
       seg[idx]+=(e-s+1)*ele;
       lazy[idx]=0;
       if(s!=e){
          lazy[2*idx+1]+=ele;
          lazy[2*idx+2]+=ele;
       }
    }
    if(s>r||l>e)return;
    if(l<=s&&r>=e){
       seg[idx]+=(e-s+1)*val;
       if(s!=e){
          lazy[2*idx+1]+=val;
          lazy[2*idx+2]+=val;
       }
       return;
    }
    ll mid=(s+e)/2;
    update(s,mid,2*idx+1,l,r,a,val);
    update(mid+1,e,2*idx+2,l,r,a,val);
    return;
}
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
        ll n,q;cin>>n>>q;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        build(0,n-1,1,a);
        while(q--){
           ll x;
           cin>>x;
           if(x==2){
              ll pos;
              cin>>pos;
              pos--;
              cout<<query(0,n-1,1,pos,a)<<"\n";
           }
           else{
              ll l,r,val;
              cin>>l>>r>>val;
              l--;r--;
              update(0,n-1,1,l,r,a,val);
           }
        }
    }
}
