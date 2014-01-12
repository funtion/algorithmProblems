#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n;#include <iostream>
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
            return i;
}
int main(){
    fib[0] = 1;
    fib[1] = 2;
    for(int i=3;;i++){
        fib[i] = fib[i-1]+fib[i-2];
        if(fib[i]>1000)
            break;
    }

    int m,n,p;
    while(cin>>m,n,p){
        int  k =f(m)^f(n)^f(p);
        cout<<(k?"Kiki":"Cici")<<endl;
    }
}
int s[600000];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if( s[i] *2  <= s[n-1-i])
            k++;
        else
            break;
    }
    cout<<n-k<<endl;
    return 0;
}