#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//浮点几何函数库
#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
struct line{point a,b;};

//计算cross product (P1-P0)x(P2-P0)
inline double xmult(point p1,point p2,point p0){
  return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline int opposite_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)<-eps;
}
int n;
point ps[400];
inline double run(int a,int b, int c, int d){
    point pa=ps[a],pb=ps[b],pc=ps[c],pd=ps[d];
    if(opposite_side(pa,pb,pc,pd))
        return abs(xmult(pc,pd,pa))+abs(xmult(pc,pd,pb));
    else if(opposite_side(pa,pc,pb,pd))
        return abs(xmult(pb,pd,pa))+abs(xmult(pb,pd,pc));
    else if(opposite_side(pa,pd,pb,pc))
        return abs(xmult(pb,pc,pa))+abs(xmult(pb,pc,pd));
    else if(opposite_side(pb,pc,pa,pd))
        return abs(xmult(pa,pd,pb))+abs(xmult(pa,pd,pc));
    else if(opposite_side(pb,pd,pa,pc))
        return abs(xmult(pa,pc,pb))+abs(xmult(pa,pc,pd));
    else if(opposite_side(pc,pd,pa,pb))
        return abs(xmult(pb,pa,pc))+abs(xmult(pb,pa,pd));
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ps[i].x>>ps[i].y;
    }
    double ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    ans = max(ans,run(i,j,k,l));
                    //cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
                    //cout<<ans<<endl;;
                }
            }
        }
    }
    cout<<fixed<<setprecision(6)<<ans/2;
    return  0;
}
