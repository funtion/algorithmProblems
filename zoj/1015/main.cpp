#include <iostream>
#include <cstring>
int m,n;
using  std::cin;
using std::cout;
bool g[1024][1024],used[1024];//,checked[1024];
int label[1024],set[1024];
void re(){
    memset(used,false,sizeof(used));
    memset(label,0,sizeof(label));
    for(int i=n;i>=1;i--){
        int maxv=-1,maxl=-1;
        for(int j=1;j<=n;j++){
            if(!used[j] && label[j] > maxv){
                maxv = label[j];
                maxl = j;
            }
        }
        used[maxl] = true;
        set [i] = maxl;
        for(int j=1;j<=n;j++){
            if(g[maxl][j]){
                label[j]++;
            }
        }
    }

}
bool check(){
    for(int i=1;i<=n;i++){
        int temp[1024];
        memset(temp,0,sizeof(temp));
        int t=0;
        for(int j=i+1;j<=n;j++){
            if(g[ set[i] ][ set[j] ]){
                temp[++t] = set[j];
            }
        }
/*
        for(int j=2;j<=t;j++){
            if(!g[temp[j]][temp[1]]){
                return false;
            }
        }
*/
        for(int j=1;j<=t;j++){
            for(int k=j+1;k<=t;k++){
                if(!g[temp[k]][temp[j]]){
                    return false;
                }
            }
        }
    }
    return true;
}


int main()
{
    while(cin>>n>>m,m+n!=0){
        memset(g,false,sizeof(g));
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            g[a][b] = g[b][a] = true;
        }
        re();
        if(check()){
            cout<<"Perfect\n\n";
        }else{
            cout<<"Imperfect\n\n";
        }
    }
    return 0;
}
