#include <iostream>

using namespace std;
long n,m,nn;
long t[2<<18];
int main()
{
    cin>>n>>m;
    nn = 2<<n;
    for(long i=1;i<=nn;i++){
        cin>>t[i];
    }
    int k=1;
    long cg=nn/2,ct=0;
    for(long i=nn+1;i<nn*2;i++){
        if(k){
            t[i] = t[i/2]|t[i/2-1];
        }else{
            t[i] = t[i/2]&t[i/2-1];
        }
        ct++;
        if(ct>=cg){
            ct=0;
            cg/=2;
            k^=1;
        }
    }
    int p,q;
    for(int i=0;i<m;i++){
        cin>>p>>q;
        t[p] = q;
        int pr=p;
        for(int j=0;j<n;j++){
            if(pr%2){
                pr=(pr+1)<<1;
            }
        }
    }
    return 0;
}
