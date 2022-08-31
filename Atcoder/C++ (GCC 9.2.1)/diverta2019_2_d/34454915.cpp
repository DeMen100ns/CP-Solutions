#include <bits/stdc++.h>
#include <regex>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < n;++i)
#define reps(i, s, n) for (int i = s; i < n;++i)
#define repr(i, s) for(int i = s; i >= 0;--i)
#define repre(i, s, e) for(int i = s; i >= e;--i)
#define ALL(a) (a).begin(),(a).end()
#define cinv(a,n) rep(i,n)cin>>a[i]
#define cinvi(a,n) vi a(n);rep(i,n)cin>>a[i]
#define cinvim(a,n) cinvi(a,n);rep(i,n)a[i]--
#define cinvl(a,n) vl a(n);rep(i,n)cin>>a[i]
#define cinvs(a,n) vs a(n);rep(i,n)cin>>a[i]
#define cinvi2(a,b,n) vi a(n),b(n);rep(i,n)cin>>a[i]>>b[i]
#define cinvl2(a,b,n) vl a(n),b(n);rep(i,n)cin>>a[i]>>b[i]
#define cinvpi(a,n) vp a(n);rep(i,n){int x,y;cin>>x>>y;a[i]={x,y};}
#define cinvpl(a,n) vpl a(n);rep(i,n){ll x,y;cin>>x>>y;a[i]={x,y};}
#define cinvvi(a,n,m) vvi a(n,vi(m));rep(i,n)rep(j,m)cin>>a[i][j]
#define cinvvl(a,n,m) vvl a(n,vl(m));rep(i,n)rep(j,m)cin>>a[i][j]
#define cint(a) int a;cin>>a
#define cinl(a) ll a;cin>>a
#define cins(s) string s;cin>>s
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define pb push_back
#define popb pop_back
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define printif(a,b,c) cout<<(a?b:c)
#define printch(a,b,c) cout<<(a==b?c:a)
#define chif(a,b,c) if(a==b)a=c
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi=vector<vvi>;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using ul = unsigned ll;
using vul = vector<ul>;
using vvul = vector<vul>;
using vs=vector<string>;
using Pi = pair<int,int>;
using Pl=pair<ll,ll>;
using vp=vector<Pi>;
using vpl=vector<Pl>;
using vvp=vector<vp>;
using vvpl=vector<vpl>;
using mint=modint;
using vm=vector<mint>;
using vvm=vector<vm>;
using vvvm=vector<vvm>;
ll max(int a,ll b){return (ll)(a>b?a:b);}
ll max(ll a,int b){return (ll)(a>b?a:b);}
ll min(int a,ll b){return (ll)(a<b?a:b);}
ll min(ll a,int b){return (ll)(a<b?a:b);}
template<typename T,typename U>
bool chmax(T& a, const U& b){if(a < b){a=b;return true;}return false;}
template<typename T,typename U>
bool chmin(T& a, const U& b){if(a > b){a=b;return true;}return false;}
template<typename T,typename U>
void chgcd(T& a, const U& b){a=gcd(a,b);}
template<typename T>
void comp(vector<T> &a){set<T>s;rep(i,a.size())s.insert(a[i]);map<T,int>idx;int i=0;for(auto x:s){idx[x]=i;i++;}rep(i,a.size())a[i]=idx[a[i]];}
template<typename T>
void print(vector<T> &a,string s=" "){for(auto x:a)cout<<x<<s;}
template<typename T>
void print(vector<T> &a,T add,string s=" "){for(auto x:a)cout<<x+add<<s;}
template<typename T>
void print(vector<vector<T>> &a,string s=" "){for(vector<T> &v:a){print(v,s);cout<<endl;}}
template<typename T>
void print(vector<vector<T>> &a,T add,string s=" "){for(vector<T> &v:a){print(v,add,s);cout<<endl;}}
void set_mod(int m){mint::set_mod(m);}
//*
const int mod=998244353;
//*/const int mod=1e9+7;
ll powmod(ll x,ll n,const ll m=mod){if(n<0)return 0;if(n==0)return 1;x%=m;if(n%2)return x*powmod(x,n-1,m)%m;else return powmod(x*x%m,n/2,m);}
vl F,iF;
void initF(int n){F.assign(n+1,1);iF.assign(n+1,1);rep(i,n)F[i+1]=(i+1)*F[i]%mod;rep(i,n+1)iF[i]=powmod(F[i],mod-2);}
ll fact(ll n){if(n==1)return 1;return n*fact(n-1);}
ll commod(int n,int r){if(min(n,r)<0||n<r)return 0;return F[n]*iF[r]%mod*iF[n-r]%mod;}
ll com(int n,int r){ll t=1;for(ll i=0;i<r;i++){t*=(n-r+1+i);t/=(i+1);}return t;}
vvi mkgraph(int n,int m,bool d=false){vvi g(n);rep(i,m){int a,b;cin>>a>>b;a--,b--;g[a].push_back(b);if(!d)g[b].push_back(a);}return g;}
vvi mkgraph(int n,vp e,bool d=false){vvi g(n);rep(i,(int)e.size()){auto[a,b]=e[i];g[a].push_back(b);if(!d)g[b].push_back(a);}return g;}
vvpl mkcgraph(int n,int m,bool d=false){vvpl g(n);rep(i,m){ll a,b,c;cin>>a>>b>>c;a--,b--;g[a].push_back({b,c});if(!d)g[b].push_back({a,c});}return g;}
vvi mktree(int n){return mkgraph(n,n-1);}
vl dijk(vvpl &g,int s,vi &prev,bool d=false){vl cost(g.size(),LLONG_MAX);prev.resize(g.size(),-1);if(!d)cost[s]=0;priority_queue<Pl,vpl,greater<Pl>>q;q.push({0,s});while(q.size()){auto[tc,t]=q.top();q.pop();if(cost[t]!=tc&&cost[t]!=LLONG_MAX)continue;for(auto[n,c]:g[t])if(chmin(cost[n],tc+c)){q.push({tc+c,n});prev[n]=t;}}return cost;}
vl dijk(vvpl &g,int s,bool d=false){vi prev;return dijk(g,s,prev,d);}
vl bellfo(vvpl &g,int s){int N=g.size();vl res(N,LLONG_MAX);res[s]=0;rep(i,2*N){rep(t,N){if(res[t]==LLONG_MAX)continue;for(auto[n,c]:g[t]){if(res[t]==LLONG_MIN)res[n]=LLONG_MIN;else if(chmin(res[n],res[t]+c)&&i>=N-1){res[n]=LLONG_MIN;}}}}return res;}
bool bg(vvi &g,vi &c){c.assign(g.size(),-1);c[0]=0;queue<int>q;q.push(0);while(q.size()){int t=q.front();q.pop();for(int n:g[t]){if(c[n]==c[t])return false;if(c[n]==-1){c[n]=1-c[t];q.push(n);}}}return true;}
bool bg(vvi &g){vi c; return bg(g,c);}
vi dep(vvi &g,int s){queue<int>q;vi res(g.size(),INT_MAX);res[s]=0;q.push(s);while(q.size()){int t=q.front();q.pop();for(int n:g[t])if(chmin(res[n],res[t]+1))q.push(n);}return res;}
int tdia(vvi &t){vi dis=dep(t,0);int s=max_element(ALL(dis))-dis.begin();dis=dep(t,s);return *max_element(ALL(dis));}
int gdia(vvi &g){int res=0;rep(i,(int)g.size()){vi dis=dep(g,i);chmax(res,*max_element(ALL(dis)));}return res;}
ll isqrt(ll x){ll r=sqrt(x);while((r+1)*(r+1)<=x)r++;while(r*r>x)r--;return r;}
vi mkiota(int n,int s=0){vi res(n);iota(ALL(res),s);return res;}
vi mkr(vi &p){int n=p.size();vi r(n);rep(i,n)r[p[i]]=i;return r;}
int biti(int bit,int i){return bit>>i&1;}
ll sqsum(ll a,ll b){return a*a+b*b;}
void bfs(vvi &g,vl &c){
  queue<int>q;
  q.push(0);
  vi used(g.size());
  while(q.size()){
    int t=q.front();
    q.pop();
    used[t]=1;
    for(int n:g[t]){
      if(used[n])continue;
      c[n]+=c[t];
      q.push(n);
    }
  }
}


ll M,N,K,Q,H,W;
string S,T;
const string yes="Yes",no="No";
const int dx[9]={0,1,0,-1,1,1,-1 ,-1,0},dy[9]={1,0,-1,0,1,-1,1,-1,0};
bool canmove(int nx,int ny){return 0<=nx&&nx<H&&0<=ny&&ny<W;}

ll calc(vvl &m){
  vl dp(N+1);
  reps(i,1,N+1)rep(j,3){
    int c=i-m[0][j];
    chmax(dp[i],dp[i-1]+1);
    if(c>=0)chmax(dp[i],dp[c]+m[1][j]);
  }
  return dp[N];
}
int main(){
  fast_io;
  cin>>N;
  cinvvl(m,2,3);
  N=calc(m);
  swap(m[0],m[1]);
  cout<<calc(m);
}