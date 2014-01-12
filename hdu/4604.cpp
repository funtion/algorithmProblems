#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,t,a[100010],b[100010],g1[100010],g2[100010];
    cin>>t;
    while(t--){
        int ans = 0;
        cin>>n;
        for(int i=n-1;i>=0;i--){
            cin>>a[i];
            b[i] = -a[i];
        }

        for(int i=1;i<=n;i++){
            g1[i] = 0x3f3f3f;
            g2[i] = 0x3f3f3f;
        }
        for(int i=0;i<n;i++){
            int k1 = upper_bound(g1+1,g1+n+1,a[i])-g1;
            int k2 = upper_bound(g2+1,g2+n+1,b[i])-g2;
            int k3 = lower_bound(g2+1,g2+n+1,b[i])-g2;
            g1[k1] = a[i];
            g2[k2] = b[i];
            /*
            for(int i=1;i<=n;i++)
                cout<<g1[i]<<' ';
            cout<<endl;
            for(int i=1;i<=n;i++)
                cout<<g2[i]<<' ';
            cout<<endl;
            cout<<k1<<":"<<k3<<endl;
            */
            ans = max(ans,k1+k3-1);
        }
        cout<<ans<<endl;
    }
}
