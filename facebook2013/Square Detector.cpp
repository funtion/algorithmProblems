#include<iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        char mp[30][30];
        int a=100,b = -1,c=-1,d = -1;
        int n;
        int cnt =0;
        cin>>n;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin>>mp[j][k];
                if(mp[j][k] == '#')
                    cnt++;
                if( mp[j][k] == '#' && j <a ){
                    a= j;
                    b= k;
                }
                if(mp[j][k] == '#' && (j>c || k >d)){
                    c=j;
                    d=k;

                }
            }
        }
        bool ans = true;
        for(int j=a;j<=c;j++){
            for(int k=b;k<=d;k++){
                if(mp[j][k] != '#')
                {
                    ans = false;
                    break;
                }
            }
        }
        if( cnt != (c-a+1)*(d-b+1))
            ans = false;
        //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
        //cout<<cnt<<endl;
        cout<<"Case #"<<i<<": "<<(ans?"YES":"NO")<<endl;
    }
}
