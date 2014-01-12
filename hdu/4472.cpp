#include<iostream>
const int m = (int)1e9+7;
using namespace std;
int a[1010]={0,1,1,2,3};
void init(){
    for(int i=5;i<=1000;i++){
        a[i]=a[i-1];
        for(int j=2;j<i;j++){
            if((i-1-j)%j==0){
                a[i] = (a[i]+a[(i-1-j)/j+1])%m;
            }
        }
    }
}
int main(){
    init();
    int n,c=0;
    while(cin>>n){
        cout<<"Case "<<++c<<": "<<a[n]<<endl;
    }
}
