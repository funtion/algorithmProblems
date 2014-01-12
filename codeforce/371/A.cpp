#include<iostream>
using namespace std;
int a[200];
int cnt[200][5];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans = 0;
    for(int i=0;i<n;i+=k){
        for(int j=0;j<k;j++){
            //cout<<i<<' '<<j<<' '<<k<<endl;
            //cout<<"del"<<i+j<<":"<<a[i+j]<<endl;
            cnt[j][a[i+j]]++;
        }

    }
    int d = n/k;
    for(int i=0;i<k;i++){
        //cout<<i<<' '<<cnt[i][1]<<' '<<cnt[i][2]<<endl;
        ans+=d-max(cnt[i][1],cnt[i][2]);
    }
    cout<<ans<<endl;
    return 0;
}
