#include <iostream>
#define maxn 1000000
#define maxm 10000
typedef int T;
using namespace std;
T m,n;
T a[maxn+1] ;
int main()
{
    while(cin>>n>>m){
        for(T i=0;i<=maxn;i++){
            a[i] = 0;
        }
        for(T i=0;i<n;i++){
            if(a[i] == 0 ){
                a[i] = i;
            }
        }
        T t;
        for(T i=0;i<m;i++){
            cin>>t;
            cout<<a[t]<<endl;
        }
    }
    return 0;
}
