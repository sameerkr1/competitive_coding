signed main(){
        ll n;cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        set<ll>st;
        st.insert(a[0]);
        for(ll i=1;i<n;i++){
           if(st.find(a[i])!=st.end())con;
           auto it=st.upper_bound(a[i]);
           if(it!=st.end())st.erase(it);
           st.insert(a[i]);
        }
        cout<<st.size()<<"\n";
}
