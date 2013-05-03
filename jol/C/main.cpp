#include <iostream>
#include <vector>
#define maxn (T)1e18
typedef long long  T;
using namespace std;

const T m = 7+1e9;

int main()
{
    T f0,f1,a,b,n;
    while(cin>>f0>>f1>>a>>b>>n){
        vector<T> t(n);
        t[0] = f0;
        t[1] = f1;
        for(T i=2;i<=n;i++){
            t[i] = (t[i-1]*a + t[i-2]*b)%m;
    }
        cout<<t[n]<<endl;
    }
    return 0;
}
