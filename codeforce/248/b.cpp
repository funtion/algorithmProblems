#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<"-1\n";
    }else if(n==3){
        cout<<"210\n";
    }else{
        int k = 1;
        for(int i=1;i<n;i++){
            k = (k*10)%21;
        }
        int c = 0;
        for(int i=0;i<100;i++){
            if( (10*i)%21 == 21-k)
                {
                    c = i;
                    break;
                }
        }
        cout<<1;
        for(int i=0;i<n-4;i++){
            cout<<0;
        }
        if(c<10)cout<<0;
        cout<<c;
        cout<<"0\n";
    }
    return 0;
}