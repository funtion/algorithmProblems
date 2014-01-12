#include <cstdio>
using namespace std;
char in[1000100];
bool ck(int x){
    int ct = 0;
    while(x){
        if(x%2==1){
            ct++;
            if(ct>=2){
                return false;
            }
        }
        x/=2;
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        if(in[0]!='M'||in[1]=='\0'){
            puts("No");
            continue;
        }
        int ci=0,cu=0;
        bool ok = true;
        for(int i=1;in[i];i++){
            if(in[i]=='I')ci++;
            else if(in[i]=='U')cu++;
            else ok = false;
        }
        if(!ok){
            puts("No");
            continue;
        }else{
            ci+=cu*3;
            ok = false;
            for(int i=0;i<0x3f3f;i++){
                if(ck(ci+i*6)){
                    puts("Yes");
                    ok = true;
                    break;
                }
            }
            if(!ok){
                puts("No");
            }
        }
    }
}
