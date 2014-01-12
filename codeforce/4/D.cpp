#include<iostream>
#include<algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,w,h;
struct bx{
    int w,h,id;
}bs[6000],b[6000];
bool cmp(const bx&l,const bx& r)
{
    if(l.w==r.w)
        return l.h<r.h;
    return l.w<r.w;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>w>>h;
    for(int i=0;i<n;i++){
        cin>>bs[i].w>>bs[i].h;
        bs[i].id = i+1;
    }
    memcpy(b,bs,sizeof(bs));
    sort(bs,bs+n,cmp);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(bs[i].w>w&&bs[i].h>h&&(ans.size()==0 || bs[i].h>b[ans.back()-1].h)){
            ans.push_back(bs[i].id);
            w = bs[i].w;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}
