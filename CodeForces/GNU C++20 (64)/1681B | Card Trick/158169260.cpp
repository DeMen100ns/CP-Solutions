#define taskname "6"
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
struct node
{
    node *l, *r;
    int wt, sz;
    int val;
    node (int v)
    {
        l = r = nullptr;
        wt = rand();
        sz = 1;
        val = v;
    }
};
 
int get_sz(node *x)
{
    if (x==nullptr) return 0;
    return x->sz;
}
 
void split(node *x, node *&l, node *&r, int k)
{
    if (x==nullptr) l = r = nullptr;
    else
    {
        if (get_sz(x->l) < k)
        {
            split(x->r, x->r, r, k - get_sz(x->l) - 1);
            l = x;
        }
        else
        {
            split(x->l, l, x->l, k);
            r = x;
        }
        x->sz = get_sz(x->r) + get_sz(x->l) + 1;
    }
}
 
void merg(node *&x, node *l, node *r)
{
    if (l==nullptr) x = r;
    else if (r==nullptr) x = l;
    else
    {
        if (l->wt < r->wt)
        {
            merg(l->r, l->r, r);
            x = l;
        }
        else
        {
            merg(r->l, l, r->l);
            x = r;
        }
        x->sz = get_sz(x->r) + get_sz(x->l) + 1;
    }
}
 
void print(node *x)
{
    if (x==nullptr) return;
    print(x->l);
    cout<<x->val<<" ";
    print(x->r);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while (t--)
    {
        int n,m;
        cin>>n;
        node *treap = 0;
        for (int i=1, x; i<=n; i++) cin>>x, merg(treap, treap, new node(x));
        cin>>m;
        //print(treap); cout<<"\n";
        while (m--)
        {
            int x;
            cin>>x;
            node *a, *b;
            split(treap, a, treap, x);
            merg(treap, treap, a);
        }
        //print(treap);
        //cout<<"\n";
        node *a;
        split(treap, a, treap, 1);
        cout<<a->val<<"\n";
    }
}