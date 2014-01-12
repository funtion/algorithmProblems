#include <iostream>
#include <cstdio>
using namespace std;
long long t,n,x,ss;
int main(){
    scanf("%I64d",&t);//cin>>t;
    while(t--){
        scanf("%I64d",&n);//cin>>n;
        ss=0;
        for(long long i=0;i<n;i++){
            scanf("%I64d",&x);//cin>>x;
            x/=2;
            ss+=(x%2);//cout<<"ss:"<<ss<<endl;
        }
        if(ss%2 == 0 )
        {
            puts("Dave");
        }
        else
        {
            puts("Carol");
        }
    }
}
