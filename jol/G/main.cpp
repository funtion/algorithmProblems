#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 100002
typedef long long  T;
T m,n;
T ps[maxn];
T po[maxn];
bool cmp(T a, T b){
    return a>b;
}
using namespace std;
int main()
{
    while(cin>>n>>m){
        T t;
        for(T i=0;i<n;i++){
            cin>>t;
            ps[i]= t;
            po[i]= t;
        }
        vector<T> pss(ps,ps+n);
        sort(pss.begin(),pss.end(),cmp);

        for(T i=0;i<m;i++){
            cin>>t;
            T num = 0;
            while( pss[num]>po[t-1])
                num++;
            cout<<num+1<<endl;
        }
       cout<<endl;
    }
    return 0;
}
