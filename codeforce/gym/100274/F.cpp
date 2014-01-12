#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int c;
    scanf("%d",&c);
    int cnt[26];
    char x;
    scanf("%c",&x);

    char in[2000];
    while(c--){
        //printf("%d",c);
        for(int i=0;i<26;i++)
            cnt[i] = 0;

        int cx = 0;

        while(scanf("%c",&x)==1&&x!='\n'){

            if(x != ' '){
                cnt[x-'A']++;
            }
            in[cx++] = x;
        }
        in[cx] = '\0';
        int mx = 0,mp =0 ;
        for(int i=0;i<26;i++){
            if(cnt[i]>mx){
                mx = cnt[i];
                mp = i;
            }
        }
        int xx = 0;
        for(int i=0;i<26;i++){
            if(cnt[i] == mx)
                xx++;
        }
        if(xx > 1 ){
            puts("NOT POSSIBLE");
        }else{

            int d = mp-4;
            if(d<0)
                printf("%d ",d+26);
            else if(d>=26)
                printf("%d ",d-26);
            else
                printf("%d ",d);
            for(int i=0;in[i];i++){
                if(in[i]==' ')
                    printf(" ");
                else{
                    char t = in[i]-d;
                    if(t<'A')t+=26;
                    if(t>'Z')t-=26;
                    printf("%c",t);
                }
            }
        }
    }
}
