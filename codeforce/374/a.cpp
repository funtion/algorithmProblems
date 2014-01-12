#include <iostream>
#include <climits>
using namespace std;
int main(){
    int m,n,ii,jj,a,b;
    cin>>n>>m>>ii>>jj>>a>>b;
    int x[]={1,1,n,n};
    int y[]={1,m,1,m};
    int ans = INT_MAX;
    for(int i=0;i<4;i++){
        int dx = ii - x[i];
        if(dx<0)dx*=-1;
        int dy = jj - y[i];
        if(dy<0)dy*=-1;
        if(dx % a ==0 && dy%b == 0){
            int xx = dx/a,yy = dy/b;
            //cout<<dx<<' '<<dy<<' '<<xx<<' '<<yy<<endl;
            int kk = max(xx,yy)-min(xx,yy);
            if(kk%2==0){
                ans = min(ans,max(xx,yy));
            }
        }
    }
    if(ans == INT_MAX){
        cout<<"Poor Inna and pony!\n";
    }else{
        cout<<ans<<endl;
    }
    return 0;
}