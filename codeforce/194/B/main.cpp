#include <iostream>
#include <algorithm>
using namespace std;
struct pt{
long long x,y;
}ps[8];
bool cmp(const pt&l,const pt&r){
    if(l.x == r.x)
        return l.y<r.y;
    return l.x<r.x;
}
bool check(){
    if(ps[0].x==ps[1].x && ps[1].x==ps[2].x && ps[3].x == ps[4].x && ps[5].x==ps[6].x &&ps[6].x==ps[7].x){
        if(ps[0].y==ps[3].y && ps[3].y==ps[5].y && ps[1].y==ps[6].y && ps[2].y==ps[4].y &&ps[4].y==ps[7].y){
            if(ps[0].y!=ps[1].y && ps[1].y!=ps[2].y && ps[3].y != ps[4].y && ps[5].y!=ps[6].y &&ps[6].y!=ps[7].y){
                if(ps[0].x!=ps[3].x && ps[3].x!=ps[5].x && ps[1].x!=ps[6].x && ps[2].x!=ps[4].x &&ps[4].x!=ps[7].x){
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    for(int i=0;i<8;i++){
        cin>>ps[i].x>>ps[i].y;
    }
    sort(ps,ps+8,cmp);
    if(check())
        cout<<"respectable\n";
    else
        cout<<"ugly\n";
    return 0;
}
