#include <iostream>
#include <cmath>

using namespace std;
//char p[1000000005];
bool pr[1000000005];
int t,k;
long long n;
inline bool tt(const long long x){
    //if(p[x] == 1)
    //    return true;
   // else if(p[x] == -1)
   //     return false;
    long long xx = (long long )sqrt(x);
    if(xx*xx == x){
   //     p[x] = 1;
        return true;
    }
  //  p[x] = -1;
    return false;
    //return p[x];
}
bool dfs(const long long x,int kk){
    if(kk == k ){
        return !tt(x);
    }
    else{
       // if(!pr[x] && k-kk!=1){
       //     return false;
       // }
        for( long long i = 2;i<=sqrt(x);i++){
            if( x%i == 0 && !tt(i)  ){
                if(dfs(x/i,kk+1))
                    return true;
            }
        }
        return false;
    }
}
int main()
{
    //for(long long i=1;i*i<1000000000;i++)
    //    p[i*i] = true;
    //q = new bool[1000000005];
    //for(long long i=2;i</stack05;i++){
    //            if(!pr[i]){
   //                 for(long long j=i+i;j<1000000005;j+=i){
   //                     pr[j] = true;
     //               }
   //             }
     //       }
    cin>>t;
    while(t--){
        cin>>n>>k;

        if(n>500000000){
            if(n%2==1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
            continue;
        }


        if(dfs(n,1))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
