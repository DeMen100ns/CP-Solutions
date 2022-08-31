#include <bits/stdc++.h>
#define taskname "herding"
#define maxn 1510
using namespace std;
int n,a[maxn];
int pre[maxn][26];
int ans[maxn][26];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    freopen(taskname".in","r",stdin);
//    freopen(taskname".out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        char c; cin>>c;
        pre[i][c-'a']++;
        for (int j=0; j<26; j++) pre[i][j]+=pre[i-1][j];
    }
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
            for (int c=0; c<26; c++)
            {
                int temp=(j-i+1)-pre[j][c]+pre[i-1][c];
//                cout<<i<<" "<<j<<" "<<c<<" "<<temp<<endl;
                ans[temp][c]=max(ans[temp][c],(j-i+1));
            }
    for (int i=1; i<=n; i++)
        for (int c=0; c<26; c++)
            ans[i][c]=max(ans[i-1][c],ans[i][c]);
    int q; cin>>q;
    for (int i=1; i<=q; i++)
    {
        int x; char c; cin>>x>>c;
//        cout<<int(c-'a')<<"  ";
        cout<<ans[x][c-'a']<<"\n";
    }
}