#include <iostream>
#include <algorithm>
using namespace std ;
typedef long long ll;
int add[200000],a[200000];
int n,q;
ll sum;
int main(){
    ios::sync_with_stdio(0);
    while(cin>>n>>q){
        sum  = 0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                sum+=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<200000;i++)
            add[i] = 0;
        int l,r,c;
        for(int i=0;i<q;i++){
            cin>>l>>r>>c;
            for(int j=l;j<=r;j++)
                add[j]=c;
        }
        for(int i=0;i<n;i++){
            int t = a[i];
            while(add[t]){
                sum+=add[t];
                t +=add[t];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}