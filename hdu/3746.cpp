#include<cstdio>
#include<cstring>
char str[100100];
int fail[100100];
int len ;
using namespace std;
void init(){
    fail[1] = 0;
    len = strlen(str+1);
    int j = 0;
    for(int i=2;i<=len;i++){
        while( j>0 && str[j+1]!=str[i])
            j = fail[j];
        if(str[j+1] == str[i])
            j++;
        fail[i] = j;
        printf("%d %d\n",i,j);
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",str+1);
        init();
        int mp = len - fail[len];
        if(mp == len) {
            printf("%d\n",mp);
        }else if(len%mp == 0){
            printf("%d\n",0);
        }else{
            printf("%d\n",mp - len%mp);
        }

    }
}
