#include<cstdio>
#include<cstring>
inline char f(char x){
    if('a'<=x && x<='z'){
        return 'A'+x-'a';
    }else if('A'<=x && x<='Z'){
        return 'a'+x-'A';
    }else{
        return x;
    }
}
int main(){
    char temp[5000];
    while(gets(temp)!=NULL){
        int lan = 0;
        int len = strlen(temp);
        for(int i=0;i<len;i+=16){
            printf("%04x: ",lan);
            lan+=16;
            int j = i;
            for(;temp[j]&&j<i+16;j++){
                printf("%02x",temp[j]);
                if(j%2==1){
                    printf(" ");
                }
            }
            while(j<i+16){
                printf("  ");
                if(j%2==1)
                    printf(" ");
                j++;
            }
            for(j=i;temp[j]&&j<i+16;j++){
                printf("%c",f(temp[j]));
            }
            puts("");
        }

    }
    return 0;
}
