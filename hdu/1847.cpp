#include <iostream>
using namespace std;
bool sg[2000];

int main(){
    sg[1] = true;
    for(int i=2;i<=1000;i++){
        for(int j=1;j<=i;j*=2){
            if(sg[i-j] == false)
                sg[i] = true;
        }
    }
    int n;
    while(cin>>n){
        cout<<(sg[n]?"Kiki":"Cici")<<endl;
    }
}