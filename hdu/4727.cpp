#include<iostream>
using namespace std;
int main(){
    int t,n,num[100100];
    cin>>t;
    for(int c=1;c<=t;c++){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>num[i];
        bool a = false;
        for(int i=2;i<=n;i++){
            if(num[i]!=num[i-1]+1){
                cout<<"Case #"<<c<<": "<<i<<endl;
                a = true;
                break;
            }
        }
        if(!a){
            cout<<"Case #"<<c<<": "<<1<<endl;
        }
    }
}
