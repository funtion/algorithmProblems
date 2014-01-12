#include <iostream>
#include <cstdio>
using namespace std;
int t;
typedef long long ll;
ll x,y;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&x);
        if(x%2==1){
            y = x/2;
            y = y*(y+1);

        }else{
            if(x%4==0){
                y = x/2;
                y = (y-1)*(y+1);
            }else{
                y = x/2;
                y = (y-2)*(y+2);
            }
        }
        printf("%I64d\n",y);
    }
    return 0;
}
