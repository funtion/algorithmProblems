#include <iostream>
using namespace std;
int in[200],out[200];
int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        in[a]+=c;
        out[b]+=c;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(in[i]>=out[i]){
            ans+=in[i]-out[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}