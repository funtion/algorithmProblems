#include <iostream>
using namespace std;
char s[5][5];
int cnt[10];
int main()
{
    int k;
    cin>>k;
    for(int i=0;i<4;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(s[i][j]!='.'){
                cnt[s[i][j]-'0']++;
            }
        }
    }
    bool ok = true;
    for(int i=1;i<=9;i++){
        if(cnt[i] > k*2){
            ok = false;
        }
    }
    if(ok){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}