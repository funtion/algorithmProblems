#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
char s[200],ans[200];
std::vector<int> v;
int main()
{
    cin>>n>>s;
    int len = strlen(s);
    bool ok = true;
    for(int i=0;i<n;i++)
        v.push_back(i);
    for(int i = 0;i<len;i++){
        if(s[i] != '?'){
            vector<int>::iterator it = find(v.begin(),v.end(),s[i]-'a');
            if(it != v.end())
                v.erase(it);
        }
    }

    for(int i=0,j=len-1;i<=j;i++,j--){
        if(s[i] == s[j] ){
            if(s[i]!='?')
                ans[i] = ans[j] = s[i];
            else{
                ans[i] = ans[j] = '?';
            }
                
        }else{
            if(s[i] == '?'){
                ans[i] = ans[j] = s[j];
            }else if(s[j] == '?'){
                ans[i] = ans[j] = s[i];
            }else{
                ok = false;
                break;
            }
        }
    }
    //for(int i=0;i<len;i++)
   //     cout<<ans[i];
    std::vector<int> vv;
    for(int i=0;i<len;i++)
        if(ans[i] == '?')
            vv.push_back(i);
    int ss = (vv.size()+1)/2;
    if(ss<v.size()){
        ok = false;
    }
    for(int i=0;i<ss;i++){
        if( ss - i > v.size())
            ans[vv[i]] = ans[len-1-vv[i]] = 'a';
        else
            ans[vv[i]] = ans[len-1-vv[i]] = 'a'+v[i-(ss-v.size())];
    }
    for(int i=0;i<len;i++)
        if(ans[i] == '?')
            ans[i] = 'a';
    if(ok){
        for(int i=0;i<len;i++)
        cout<<ans[i];
    }else{
        cout<<"IMPOSSIBLE";
    }

    return 0;
}