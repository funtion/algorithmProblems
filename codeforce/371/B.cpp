#include<iostream>
#include<algorithm>
using namespace std;
int g[] = {2,3,5};
int main(){
    int a,b;
    cin>>a>>b;
    int gg = __gcd(a,b);
    int aa = a/gg,bb = b/gg;
    int ans = 0;
    for(int i=0;i<3;i++){
        while(aa%g[i] == 0){
            ans++;
            aa/=g[i];
        }
        while(bb%g[i] == 0){
            ans++;
            bb/=g[i];
        }
    }
    if(aa==1 && bb==1){
        cout<<ans<<endl;
    }else{
        cout<<"-1"<<endl;
    }
   return 0;
}
