#include <iostream>
#include <algorithm>
using namespace std;
inline int ab(int x)
{
    return x>0?x:-x;
}
int in[100100],m,n,d;
int  main(){
    cin>>m>>n>>d;
    int nn = m*n;
    for(int i=0;i<nn;++i){
        cin>>in[i];
    }
    sort(in,in+nn);
    int ans=0,md = in[nn/2];
    for(int i=0;i<nn;i++){
        if(ab(in[i]-md)%d !=0){
            cout<<"-1";
            return 0;
        }else{
            ans+=ab(in[i]-md)/d;
        }
    }
    cout<<ans;
}
