#include <iostream>
#include <set>
#include <cstdio>
using namespace std; 
int k,m;
int s[200];
int sg[10020];
int init(int x){
    //set<int> st;
    bool ss[110];
    for(int i=0;i<=101;i++)
        ss[i] = false;
    for(int i=0;i<k;i++){
        if(x-s[i]>=0){
            ss[sg[x-s[i]]] = true;//st.insert(sg[x-s[i]]);
        }
    }
    for(int i=0;i<=10000;i++){
        if(ss[i]==false)
            return i;
    }
}
int main(){
    //ios::sync_with_stdio(0);
    while(scanf("%d",&k)!=EOF&&k!=0){
        for(int i=0;i<k;i++)
            scanf("%d",&s[i]);//cin>>s[i];
        for(int i=0;i<=10000;i++){
            sg[i] = init(i);
        }
        scanf("%d",&m);//cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d",&x);//cin>>x;
            int ans = 0;
            while(x--){
                cin>>y;
                ans^=sg[y];
            }
            printf(ans==0?"L":"W");//cout<<(ans==0?'L':'W');
        }
        puts("");//cout<<endl;
    }
    return 0;

}