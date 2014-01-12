/*
ID: funtion
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct st
{
    int l,r;
}s[6000];
bool cmp(const st&l,const st&r){
    return l.l<r.l;
}
bool f[1000010];
int n;
int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    cin>>n;
    int mxe = 0;
    int mis = 1000010;
    for(int i=0;i<n;i++)
        {
            cin>>s[i].l>>s[i].r;
            mxe = max(mxe,s[i].r);
            mis = min(mis,s[i].l);
        }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=s[i].r-1;j>=s[i].l;j--){
            if(f[j])
                break;
            f[j] = true;
        }
    }
    int a1=0;

    for(int i=mis;i<mxe;i++){
        if(f[i])       
        {
            int j=i;
                while(j+1<=mxe&&f[j+1]){
                    j++;
                }
                if(j-i+1>a1)
                    a1 = j-i+1;
                i=j;
        }
    }
    int a2 = 0;
    for(int i=mis;i<mxe;i++){
        if(!f[i]){
            int j=i;
            while(j+1<=mxe&&!f[j+1]){
                j++;
            }
            if(j-i+1>a2)
                {a2 = j-i+1;}
            i=j;
        }
    }
    cout<<a1<<' '<<a2<<endl;
    return 0;
}