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
#define pb push_back
#define all(s) s.begin(),s.end()
#define pie 3.14159265358979323846
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define gcd __gcd
#define pii pair<ll,ll>

int findParent(int node,vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findParent(parent[node]);
}

void unionByRank(int u,int v,vector<int>&parent,vector<int>&ranking){
    int up=findParent(u);
    int vp=findParent(v);
    if(up==vp)return;
    if(ranking[up]<ranking[vp]){
        parent[up]=vp;
    }
    else if(ranking[up]>ranking[vp]){
        parent[vp]=up;
    }
    else{
        parent[up]=vp;
        ranking[vp]++;
    }
}

void disjointSet(int n){
    vector<int>ranking(n+1,0),parent(n+1);
    for(int i=1;i<=n;i++)parent[i]=i;
}

signed main(){
    FASTIO;
    int tt=1;
    cin>>tt;
    while(tt--){
        ll n,k;cin>>n>>k;
        cout<<abs(n-k)<<"\n";
    }

}
