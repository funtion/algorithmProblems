#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
char s[200010];
int a[200010];
int main(){
    cin>>s;
    int n = strlen(s);
    for(int i=0;s[i];i++){
        a[i] = s[i] - '0';
    }
    a[n++] = 100;
    ll ans = 1;
    for(int i=0;i<n;){
        int j = i+1;
        for(j=i+1;j<n;j++){
            //cout<<i<<' '<<j<<' '<<a[j]+a[j-1]<<endl;
            if(a[j]+a[j-1]!=9){
                if((j-i)%2==1){
                    ans*= (j-i+1)/2;
                }
                break;
            }  
        }
        i = j;
    }
    cout<<ans<<endl;
    return 0;
}