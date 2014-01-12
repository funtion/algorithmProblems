#include <cstdio>
#include <iostream>
using namespace std;
typedef int ll;
int main(){
    int t;
    scanf("%d",&t);//cin>>t;
    while(t--){
        //ios::sync_with_stdio(0);
        ll len,n,x;
       scanf("%d%d",&len,&n);// cin>>len>>n;
        ll a=0,b=0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&x);//cin>>x;
            ll u = min(x,len-x);
            ll v = max(x,len-x);
            a = max(a,u);
            b = max(b,v);
        }
        //cout<<a<<' '<<b<<endl;
        printf("%d %d\n",a,b);
    }
    return 0;
}