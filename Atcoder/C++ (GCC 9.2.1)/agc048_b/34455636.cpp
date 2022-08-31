#include<bits/stdc++.h>
#define Un unsigned
#define LL long long
#define For1(i,a,b) for(i=(a);i<=(b);i++)
#define For2(i,a,b) for(i=(a);i<(b);i++)
#define FoR1(i,a,b) for(i=(a);i>=(b);i--)
#define FoR2(i,a,b) for(i=(a);i>(b);i--)
#define For_L(i,x) for(i=ft[x];i;i=nt[i])
#define lwbd std::lower_bound
#define upbd std::upper_bound
#define mkp std::make_pair
#define pii std::pair<int,int>
#define fir first
#define sec second
#define getchar() ((_S==_T)?((_T=(_S=_B)+fread(_B,1,(1<<15),stdin)),*_S++):*_S++) 
char _B[1<<15|15],*_S=_B,*_T=_B;
template<class T1> 
inline void cmax(T1&x,T1 y){if(x<y)x=y;}
template<class T1> 
inline void cmin(T1&x,T1 y){if(x>y)x=y;}
template<class T1=int> 
T1 Rd(){char ch;T1 aa;
	while((ch=getchar())<48);
	aa=ch^48;
	while((ch=getchar())>=48)aa=aa*10+(ch^48);
	return aa;
}
const int N=100111,inf=0x7f7f7f7f;
int a[N],c[N],n;
LL ans;
int main(){int i,t1;
	n=Rd();
	For1(i,1,n)a[i]=Rd();
	For1(i,1,n)t1=Rd(),ans+=t1,a[i]-=t1;
	For1(i,1,(n>>1))c[i]=a[(i<<1)-1],c[(n>>1)+i]=a[i<<1];
	c[0]=c[n+1]=-inf;
	std::sort(c+1,c+(n>>1)+1);std::sort(c+(n>>1)+1,c+n+1);
	FoR2(i,(n>>1),0){
		if(c[i]+c[(n>>1)+i]<0)break;
		ans+=c[i]+c[(n>>1)+i];
	}
	printf("%lld\n",ans);
}