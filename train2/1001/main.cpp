#include <iostream>
#include <cstring>
#include <cstdio>
char a[1002],b[1002];
bool c[256][256];
using namespace std;
int m;
int T;
char x,y;
int main()
{
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        memset(c,false,sizeof(c));
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        scanf("%s",a);
        scanf("%s",b);
        scanf("%d",&m);
        fflush(stdin);
        while(m--){
            scanf("%c %c",&x,&y);
            c[x][y] = true;
        }
        bool ok=false,jmp=false;
        int la = strlen(a),lb = strlen(b);
        if(la<=lb){
            for(int j=0,k=0;j<la && k<lb;j++,k++){
                while(la-j<=lb-k &&a[j]!=b[k] && !c[a[j]][b[k]]){
                    k++;
                    ok = false;
                }
                if(a[j]==b[k] || c[a[j]][b[k]])
                    ok = true;
            }
        }

        if(ok){
            printf("Case #%d: happy\n",i+1);
        }else{
            printf("Case #%d: unhappy\n",i+1);
        }
    }
}
