#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[5];
inline int calc(int x){
    if(x%1024 == 0 && x!=0)
        return 1024;
    else
        return x%1024;
}
int main()
{
    while(cin>>n){
        int ans = 0,sum=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(n<=3){
            ans = 1024;
        }else if(n==4){
            bool flag = false;
            for(int i=0;i<4;i++){
                if( (sum - a[i])% 1024 == 0){
                    ans = 1024;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                for(int i=0;i<4;i++){
                    for(int j=i+1;j<4;j++){
                        ans = max(ans,calc(a[i]+a[j]));
                    }
                }
            }
        }else{ //n==5
            for(int i=0;i<5;i++){
                for(int j=i+1;j<5;j++){
                    if( (sum-a[i]-a[j])%1024 == 0){
                        ans = max(ans,calc(a[i]+a[j]));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
