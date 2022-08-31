#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1,kM=std::__lg(kN)+1;
int n,a[kN],st[kM][kN];
int cmp(int x,int y){return a[x]<a[y]?x:y;}
struct node{
	int l,x,y,r;
	friend bool operator<(const node &_a,const node &_b){
		return cmp(_a.x,_b.x)!=_a.x;
	}
};
std::priority_queue<node>q;
int query(int l,int r){
	if(l>r)return 0;
	int t=std::__lg(r-l+1);
	return cmp(st[t][l],st[t][r-(1<<t)+1]);
}
void updata(int l,int r){
	if(l>r)return;
	int t=query(l,r);
	q.push({l,t,cmp(query(t+1,r-1),r),r});
}
signed main(){
//	freopen("Tspin.in","r",stdin);
//	freopen("Tspin.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;a[0]=n+1;
	for(int i=1;i<=n;i++)cin>>a[i],st[1][i]=i;
	for(int i=2;(1<<i)<=n;i++)for(int j=1;j+(1<<i)-1<=n;j++)
		st[i][j]=cmp(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(updata(1,n);!q.empty();){
		node u=q.top();q.pop();
		cout<<a[u.x]<<' '<<a[u.y]<<' ';
		updata(u.l,u.x-1);
		updata(u.x+1,u.y-1);
		updata(u.y+1,u.r);
	}
	return 0;
}