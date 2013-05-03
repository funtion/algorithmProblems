#include <iostream>

using namespace std;

int main()
{
    int a[200],b[200];
    int na=0,nb=0;
    int t,n;
    cin>>n;
    while(n--){
        cin>>t;
        if(t<0){
            if(na == 0){
                a[na++] =t;
            }else{
                b[nb++] =t;
            }
        }else if(t>0){
                b[nb++] =t;
        }
    }
    cout<<1<<' '<<a[0]<<endl;
    cout<<nb;
    while(nb--){
        cout<<' '<<b[nb];
    }
    cout<<endl;
    cout<<1<<' '<<0;
    return 0;
}
