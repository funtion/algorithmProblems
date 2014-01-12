#include <iostream>
typedef long long ll;
using namespace std;
ll n,sum;
int main()
{
    cin>>n;
    while(n>0){
        for(ll i=1;i<=n*3;i*=3){
            if(n%i==0)continue;
            ll k = n/i;
            if(k>0){
                sum+=k;
                n-=k*i;
            }

            else{
                sum+=1;
                n-=i;
            }

            break;
        }

    }
    cout<<sum;
    return 0;
}
