#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    char s[11000];
    int a[11000],len,ans;
    scanf("%d",&t);
    for(int cse=1;cse<=t;cse++){
        scanf("%s",s);
        len = strlen(s);
        if(len<4){
            ans = 1;
        }else{
            a[0]=a[1]=a[2]=1;
            for(int i=3;i<len;i++){
                if(s[i]=='e' && s[i-1]=='h' && s[i-2]=='e' && s[i-3]=='h'){
                    if(i-4<0){
                        a[i] = a[i-2]+1;
                    }else{
                    a[i] = a[i-4]+a[i-2];
                    a[i]%=10007;
                    }

                }else{
                    a[i] = a[i-1];
                    a[i]%=10007;
                }
            }
            ans = a[len-1];
        }
        printf("Case %d: %d\n",cse,ans);
    }
    return 0;
}
