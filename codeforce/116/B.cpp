#include <cstdio>
#include <cstring>
inline long long min(long long x,long long y){
return x<y?x:y;
}
char in[500100];
long long  l[500100],h[500100];
inline bool ck(char x){
    return x>='A'&& x<='Z';
}
int main(){
    scanf("%s",in);
    long long n = strlen(in);
    if(n==1){
        printf("0");
        return 0;
    }
    n--;
    if(ck(in[0])){
        h[0]=1;
        l[0]=0;
    }else{
        h[0]=0;
        l[0]=1;
    }
    for(long long i=1;in[i];++i){
        if(ck(in[i])){
            h[i]=h[i-1]+1;
            l[i]=l[i-1];
        }else{
            h[i]=h[i-1];
            l[i]=l[i-1]+1;
        }
        n=i;
    }
    long long ans=h[n];
    for(long long i=0;in[i];i++){
        ans = min(ans,l[i]+(h[n]-h[i+1]));
    }
    printf("%I64d",ans);
}
