#include <iostream>
#include <cstring>
using namespace std;
int t,n;
int a[3000],b[3000],c[3000],d[3000];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)b[a[i]]++;
        for(int i=0;i<n;i++){
            c[a[i]]++;
            if(c[a[i]]<=b[a[i]]/2){
                d[i]=0;
            }
            else{
                d[i]=1;
            }
        }
        for(int i=0;i<n;i++)cout<<d[i];
        cout<<endl;
    }
}
