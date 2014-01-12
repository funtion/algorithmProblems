#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
int main(){
	ll C;
	cin>>C;
	for(ll i=0;i<C;i++){
		int  n,v,w;
		cin>>n>>v>>w;
		int p[200];
		memset(p,0,sizeof(p));
		for(ll j=0;j<n;j++){
			cin>>p[j];
		}
		sort(p,p+n);
		ll num=0,sum=0;
		for(ll j=0;j<n;j++){
			if( ( sum+ p[j] ) <= w * (num+1) ){
				sum+=p[j];
				num++;
			}else{
				break;
			}
		}
		if(num==0)
			cout<<"0 0.00"<<endl;
		else
			cout<<num*v<<" "<<fixed<<setprecision(2)<<(double)sum*0.01/num<<endl;


	}
}
