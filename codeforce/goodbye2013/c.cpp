#include <iostream>
#include <algorithm>
using namespace std;
struct po
{
    int id;
    int x;
}a[400000];
int ans[400000];
bool cmp(const po& l,const po& r){
    return l.x<r.x;
}
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x;
        a[i].id = i;
    }
    sort(a,a+n,cmp); 
    int cur = 0;
    for(int i=0;i<n;i++){
        if(a[i].x == cur){
            ans[a[i].id] = ++cur;
        }
        else if(a[i].x>cur){
            ans[a[i].id] = a[i].x;
            cur = a[i].x;
        }else{
            ans[a[i].id]=++cur;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}