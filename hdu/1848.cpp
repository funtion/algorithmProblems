#include <iostream>
using namespace std;
int sg[2000];
int fib[50];
int f(int x){
    bool a[2000];
    for(int i=0;i<=1000;i++)
        a[i] = false;
    for(int i=0;fib[i]<=x;i++){
        a[sg[x-fib[i]]] = true;
    }

    for(int i=0;i<=1000;i++)
        if(a[i] == false)
        {
            sg[x] = i;
            break;
        }
    return sg[x];
}
int main(){
    fib[0] = 1;
    fib[1] = 2;
    for(int i=2;;i++){
        fib[i] = fib[i-1]+fib[i-2];
        if(fib[i]>1000)
            break;
    }
    //for(int i=0;i<10;i++)
    //    cout<<fib[i]<< ' ';
    //cout<<endl;
    for(int i=0;i<=1000;i++)
        f(i);
    //for(int i=0;i<=10;i++)
    //    cout<<i<<' '<<sg[i]<<endl;
    int m,n,p;
    while(cin>>m>>n>>p&&(m+n+p)){
        int  k =sg[m]^sg[n]^sg[p];
        cout<<(k?"Fibo":"Nacci")<<endl;
    }
}
