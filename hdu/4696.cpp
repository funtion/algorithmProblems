#include <cstdio>
using namespace std;
int main(){
    //ios::sync_with_stdio(false);
    int n,q,x;
    bool c;
    while(scanf("%d%d",&n,&q)==2){
        c = false;
        //cin>>q;
        for(int i=0;i<n;i++)
            scanf("%d",&x);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);//cin>>x;
            if(x==1)
                c = true;
        }
        for(int i=0;i<q;i++){
            scanf("%d",&x);//cin>>x;
            if(x<=0){
                puts("NO");
            }else if(c){
                puts("YES");
            }else{
                if(x%2==0)
                {
                    puts("YES");
                }
                else{
                    puts("NO");
                }
            }
        }
    }
}
