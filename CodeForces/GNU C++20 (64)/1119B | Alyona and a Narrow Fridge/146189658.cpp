#include<bits/stdc++.h>
 
using namespace std;
 
const int M=1e3+3;
 
int a[M],h,n;
 
int check(int m)
{
    vector<int> vt(a+1,a+m+1);
    sort(vt.rbegin(),vt.rend());
    int tmp=0;
    for(int i=0;i<m;i+=2)
    {
        if(tmp+vt[i]>h)return 0;
        tmp+=vt[i];
    }
    return tmp<=h;
}
 
 
void process()
{
    cin>>n>>h;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1,r=n+1;
    while(r-l>1)
    {
        int m=(l+r)/2;
        if(check(m))l=m;
        else r=m;
    }
    cout<<l;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}