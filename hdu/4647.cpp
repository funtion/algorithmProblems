
#include <iostream>
#include <algorithm>
using namespace std;
double ww[200000];
int main(){
    int m,n;
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>ww[i];
        }
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            ww[u-1]+=w/2.0;
            ww[v-1]+=w/2.0;
        }
        sort(ww,ww+n);
        double a=0,b=0;
        for(int i=0;i<n;i++){
            if(i%2==0)
                a+=ww[n-i-1];
            else
                b+=ww[n-i-1];
        }
        long long ans = a-b;
        cout<<ans<<endl;
        /*
        for(int i=0;i<n;i++){
            cout<<ww[i]<<endl;
        }
        cout<<endl<<a<<' '<<b<<endl;
        */
    }
}
