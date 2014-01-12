#include <iostream>
#include <cstring>
using namespace std;
char s[100010],ns[100010];
int k,len,nlen;
char fb[256],x,y;
int dp[100010],cnt[10010];
int main(){
    cin>>s>>k;
    len = strlen(s);
    for(int i=0;i<k;++i){
        cin>>x>>y;
        fb[x] = y;
        fb[y] = x;
    }
    int ans = 0;
    for(int i=0;i<len;){
        if( fb[s[i]] == 0)
        {
            i++;
        }
        else
        {
            int j=i,a=0,b=0;
            while(j<len && (s[j]==s[i]||s[j]==fb[s[i]]))
            {
                if(s[j] == s[i])
                    a++;
                else
                    b++;
                j++;
                //cout<<"a="<<a<<" b="<<b<<endl;
            }
            ans+=min(a,b);
            i=j;
        }

    }
    cout<<ans;
}
