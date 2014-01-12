#include <iostream>
using namespace std;
char s[200000],ss[200000];
int cnt[200000];
int k;
char fb[256];
int main(){
    cin>>s;
    int len = 0;
    for(int i=0;s[i];i++){
        int k = 0,j=i;
        ss[len] = s[i];
        while(s[j+1] && s[j+1] == s[i]){
            j++;
        }
        cnt[len] = j-i+1;
        i = j;
        len++;
    }
    ss[len] = 0;
    cin>>k;
    char a,b;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        fb[a] = b;
        fb[b] = a;
    }
    int ans = 0;
    for(int i=0;ss[i];i++){
        int j = i;
        int a = 0,b = 0;
        while(ss[j]){
            if(ss[j] == ss[i])
                a+=cnt[j];
            else
                b+=cnt[j];
            if(fb[ss[j+1]] != ss[j])
                break;
            j++;
        }
        ans+=min(a,b);
        i = j;
    }
    cout<<ans<<endl;
    return 0;
}