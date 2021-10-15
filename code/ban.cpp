#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

const int N=200005;

int n;
int a[N],cnt[N];

void init() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		cnt[a[i]]++;//装进桶
	}
}

void work() {
	ll ans=0;
	for(int i=1; i<=n; i++)
		ans+=1ll*cnt[i]*(cnt[i]-1)/2;//不带限制时的答案
	for(int i=1; i<=n; i++)
		printf("%lld\n",ans-(cnt[a[i]]-1));//减去去掉第i个球的方案数
}

int main() {
	init();
	work();
	return 0;
}
