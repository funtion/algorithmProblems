#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[200000],b[200000],c[300000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[i] = a[i];
        c[i+n] = b[i];
    }

    sort(c+1,c+n*2+1);
    //for(int i=1;i<=n*2;i++)
     //   cout<<c[i]<<endl;
    for(int i=1;i<=n;i++){
        if(i<=n/2){
            cout<<1;
        }else if(a[i]<=c[n]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(i<=n/2){
            cout<<1;
        }else if(b[i]<=c[n]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<endl;
    return 0;
}