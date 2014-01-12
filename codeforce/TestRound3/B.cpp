#include <iostream>
#include <cstdio>
using namespace std;
/*
int main(){
    int n;
    cin>>n;
    if(n<=3){
        cout<<n-1;
    }
    else{
        int a=1,b=2,c=3,k=1;
        while(c<n){
            k++;
            c=a+b;
            a=b;
            b=c;
        }
        cout<<k;
    }
}
*/
int ans;
int n;
void d(int a,int b,int k){
    if(a>n||b>n)
        return ;
    if(a==n||b==n)
    {
        ans = min(k,ans);
        return;
    }
    if(a>b)swap(a,b);
    d(b,a+b,k+1);
    d(a,a+b,k+1);
}
int main(){
    cin>>n;
    //freopen("out.txt","w",stdout);
    ans = 2000000;
    d(1,1,0);
    cout<<ans;
}
