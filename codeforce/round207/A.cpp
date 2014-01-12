#include<iostream>
using namespace std;
int main(){
    int n,sum=0,a[200],ans=0;
    int x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cin>>x>>y;
    int s1 = 0;
    for(int i=1;i<=n;i++){

        if(s1>=x&&s1<=y&&(sum-s1)>=x&&(sum-s1)<=y){
            ans = i;
            break;
        }
        s1+=a[i];
    }
    cout<<ans<<endl;
}
