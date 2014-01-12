#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll mt[310][310];
int t;
int n,m;
bool test(int x){
    for(int i=0;i+x<=n;i++){
        for(int j=0;j+x<=m;j++){
            bool flg = true;
            for(int k=i;k<i+x;k++){
                for(int l =j,h = j+x-1;l<=h;l++,h--){
                    if(mt[k][l]!=mt[k][h]){
                        //puts("xx");
                        flg = false;
                        break;
                    }
                }
                if(!flg)
                {
                    break;
                }
            }
            if(!flg){
                continue;
            }
            for(int k=j;k<j+x;k++){
                for(int l = i,h = i+x-1;l<=h;l++,h--){
                    if(mt[l][k] != mt[h][k]){
                        //puts("yy");
                        flg = false;
                        break;
                    }
                }
                if(!flg){
                    break;
                }
            }
            if(flg){
                //printf("%d %d %d\n",i,j,x);
                return true;
            }


        }
    }
    return false;
}
int main(){

    scanf("%d",&t);
    while(t--){
        //memest(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%I64d",&mt[i][j]);
            }
        }
        int ans;
        for(ans=min(m,n);ans>=1;ans--){
            if(test(ans))
                break;
        }

        printf("%d\n",ans);
    }
}
