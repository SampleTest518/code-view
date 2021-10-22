#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N=100005;
const ll oo=0x3f3f3f3f3f3f3f3f;
int n,p,q,r,a[N];
ll ans,Left[N],Right[N];
int main() {
	scanf("%d %d %d %d",&n,&p,&q,&r);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	Left[1]=1ll*a[1]*p;
	Right[n]=1ll*a[n]*r;
	for(int i=2; i<=n; i++) { 
		Left[i]=max(Left[i-1],1ll*p*a[i]);
	} //p*a[i]的前缀最大值
	for(int i=n-1; i>=1; i--) { 
		Right[i]=max(Right[i+1],1ll*r*a[i]);
	} //r*a[k]的后缀最大值
	ll ans=-oo;
	for(int i=1; i<=n; i++) {
		ans=max(ans,Left[i]+1ll*q*a[i]+Right[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
