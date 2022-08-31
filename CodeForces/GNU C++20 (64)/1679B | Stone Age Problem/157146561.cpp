#include <bits/stdc++.h>
#define For(i,a,b) for(long long i=a;i<=b;i++)
typedef long long ll;
using namespace std;
 
ll z[3];
ll a[1000000];
ll seg[1000000];
ll seg2[1000000];
const ll MOD=1e9+7;
 
void down(ll id, ll l, ll r) {
    ll t = seg2[id];
    ll mid = (l+r)>> 1;
    seg2[id<< 1] = t;
    seg[id<< 1] = t*(mid-l+1);
 
    seg2[id<< 1 | 1] = t;
    seg[id<< 1 | 1] = t*(r-mid);
 
    seg2[id] = -1;
}
 
ll get(ll id, ll l, ll r, ll u, ll v) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return seg[id];
    }
    ll mid = (l + r) >>1;
    if (seg2[id]>-1) down(id,l,r);
 
    return (get(id<< 1, l, mid, u, v) + get(id<< 1 | 1, mid+1, r, u, v));
}
 
void upd(ll id, ll l, ll r, ll u, ll v, ll val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        seg[id] = val*(r-l+1);
        seg2[id] = val;
        return ;
    }
    ll mid = (l + r) >>1;
 
    if (seg2[id]>-1) down(id,l,r);
 
    upd(id<< 1, l, mid, u, v, val);
    upd(id<< 1 | 1, mid+1, r, u, v, val);
 
    seg[id] = (seg[id<< 1] + seg[id<< 1 | 1]);
}
 
int main()
{
    //freopen("TICKET.inp","r",stdin);
    //freopen("TICKET.out","w",stdout);
    ll n,k,m;
    cin >> n >> m;
    For(i,1,n){
        cin >> a[i];
        upd(1,1,n,i,i,a[i]);
    }
    //For(i,1,4*n) seg2[i]=-1;
    For(i,1,m){
        ll type;
        ll l,r,val;
        cin >> type;
        if (type==1){
            cin >> l >> val;
            upd(1,1,n,l,l,val);
        } else {
            cin >> val;
            upd(1,1,n,1,n,val);
        }
        cout << seg[1] << endl;
    }
    return 0;
}