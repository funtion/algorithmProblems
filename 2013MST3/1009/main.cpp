#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct pt{
    int x,y;
};
struct tr{
    pt p[3];
    long double area(){}
}trs[60];
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;i<3;j++){
                scanf("%d%d",&(trs[i].p[j].x),&(trs[i].p[j].y));
            }
        }
    }
    return 0;
}
