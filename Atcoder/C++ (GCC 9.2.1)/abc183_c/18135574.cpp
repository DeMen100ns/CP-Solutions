/*
Made by : Trieu self-destruct :p
INPUT :

OUTPUT :

*/

#include <bits/stdc++.h>

using namespace std;

/*Weird define*/
#define ll long long
#define endl '\n'
#define gcd __gcd

/*For define*/
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define foR(i,a,b) for(ll i=a;i>=b;i--)
#define forN(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define foRN(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define fora(i, a) for (auto i : a)

/*push-pos define*/
#define pb push_back
#define pob pop_back

/*Print define*/
#define write(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << ' '; cout << endl
#define writeln(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << endl

/*Type-def :p*/
typedef unsigned long long 	ull;
typedef vector<ll> 		vi;
typedef pair<ll, ll>		ii;
typedef long double         ld;

/*some const*/
const ll IMA = INT_MAX;
const ll IMI = INT_MIN;
const ll MOD = 1e9+7;

/* Calculation with MODULO*/
ll add(ll x, ll y) {return (x + y) % MOD;}
ll mul(ll x, ll y) {return (x * y) % MOD;}
ll bpow(ll x, ll y) {ll res = 1; while (y) {if (y & 1) res = mul(res, x); x = mul(x, x); y >>= 1;} return res;}
ll ModInverse(ll x) {return bpow(x, MOD - 2);}
ll Div(ll x, ll y) {return mul(x, ModInverse(y));}

/*Some simple checking and calculation function*/
string yn(bool k){if (k) return "YES"; else return "NO";}
bool checkprime(ll k){if (k<2) return false;if (k==2 || k==3) return true;if (k%2==0 || k%3==0) return false;forN (i,5,sqrt(k),6){if (k%i==0 || k%(i+2)==0) return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

ll a[15][15],n,A[15],d,k;
ll Bool[15];

void xuat() {
    ll t=0;
    if (A[1]!=1) return;
    For (i,2,n){
        t+=a[A[i]][A[i-1]];
    }
    if (t+a[A[n]][1]==k) d+=1;
}

void Try(int k) {
    For (i,1,n) {
        //Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
        if (!Bool[i]) {
            A[k] = i; // Lưu một phần tử vào hoán vị
            Bool[i] = 1;//Đánh dấu đã dùng
            if (k == n)//Kiểm tra nếu đã chứa một hoán vị thì xuất
                xuat();
            else
                Try(k + 1);
            Bool[i] = 0;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    For (i,1,n){
        For(j,1,n) cin >> a[i][j];
    }
    Try(1);
    cout << d;
    return 0;
}
/*
If it WA, check :
- Special case (Usually, n=1)
- WRONG FORMAT OUTPUT
- Check reading
- Change (ll) to (ull)
- Integer Overflow (The number that bigger than 2^63-1)
*/
