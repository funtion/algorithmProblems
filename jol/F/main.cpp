#include <iostream>
typedef long long  T;
T x,y,k,n;
using namespace std;
T kkk(){
    return  (y/k +1)*k;
}
int main()
{
    while(cin>>y>>k>>n){
        T kk =kkk();
        if(kk>n){
            cout<<-1<<endl;
            continue;
        }
        cout<<kk-y;
        for(x=kk-y+k;x<=n-y;x+=k){
            cout<<" "<<x;
        }
        cout<<endl;
    }
    return 0;
}
