#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 100010
int n,m;
int a[MAX],cnt[MAX];
bool ox[MAX];
bool ddd;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    
    //a[0] = a[n+1] = INT_MAX;
    for(int i=1;i<=n;i++){
        if (a[i] < a[i-1] && a[i]<=a[i+1]){
            cnt[i] = cnt[i-1]+1;
            ox[i] = true;
        }else{
            cnt[i] = cnt[i-1];
        }
    }
    int x,y;
    for(int i=0;i<m;i++){
        //if(n == 100000 && m == 100000 && a[1] == 5&&i==56889)
        //    ddd = true;
        //ddd = false;
        scanf("%d%d",&x,&y);
        //if(ddd){
        //    printf("%d:%d",x,y);
        //    for(int i=x;i<=y;i++)
        //        printf(" %d",a[i]);
        //}
        if(y-x <=1){
            puts("Yes");
            continue;
        }
        /*
        else if(y-x<=5){

            int *p = max_element(a+x,a+y);
            //printf("%d\n",*(p+1));
            bool ok = true;
            for(int *i = a+x;i<p;i++)
                if(*i > *(i+1))
                    ok = false;
            for(int *i = p+1;i<a+y;i++)
                if(*i < *(i+1))
                    ok = false;
            if(ok)
                puts("Yes");
            else
                puts("No");
        }*/
        else if(y-x == 2){
            if(a[x]<=a[x+1]&&a[x+1]<=a[x+2])
                puts("Yes");
            else if(a[x]>=a[x+1]&&a[x+1]>=a[x+2])
                puts("Yes");
            else if(a[x]<=a[x+1]&&a[x+1]>=a[x+2])
                puts("Yes");
            else
                puts("No");
        }
        else if(cnt[y]-cnt[x-1]>2){
            puts("No");
        }else if(cnt[y]-cnt[x-1] == 2){
            if(ox[x] && ox[y])
                puts("Yes");
            else
                puts("No");

        }else if(cnt[y]-cnt[x-1] == 1){
            if(ox[x] || ox[y])
                puts("Yes");
            else if ( a[x+1] >= a[x] && a[y-1]==a[y])
                puts("Yes");
            else
                puts("No");
                
        }else{
                puts("Yes");
        }
    }
    return 0;
}