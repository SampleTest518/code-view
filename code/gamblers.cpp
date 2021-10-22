#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct node{
	int x;
	int y;
};
map<int,node> mp;
map<int,node> ::iterator it;
int a[1005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	node tmp;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tmp.x=i;
			tmp.y=j;
			mp[a[i]+a[j]]=tmp;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(a[i]!=a[j]){
				int d=a[i]-a[j];
				it=mp.find(d);
				if(it==mp.end()){
					continue;
				}
				tmp=it->second;
				if(tmp.x!=i&&tmp.x!=j&&tmp.y!=i&&tmp.y!=j){
					cout<<a[i]<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"no solution"<<endl;
	return 0;
}
