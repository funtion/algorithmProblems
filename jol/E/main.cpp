#include <iostream>
#include <cstring>
#define maxn 1000001
typedef long long T;
using namespace std;
T m,n;
T a[maxn];
int main()
{
    while(cin>>n>>m){
        memset(a,0,sizeof(a));
        T t;
        for(T i=1;i<n+1;i++){
            cin>>t;
            if(a[t] ==0)
                a[t] = i;
        }

        for(T i=0;i<m;i++){
            cin>>t;
            cout<<a[t]<<endl;
        }
    }
    return 0;
}
