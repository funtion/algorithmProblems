#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdio>
//using namespace std;
//���㼸�κ�����
#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
struct line{point a,b;};

//����cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
  return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double xmult(double x1,double y1,double x2,double y2,double x0,double y0){
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

//����dot product (P1-P0).(P2-P0)
double dmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double dmult(double x1,double y1,double x2,double y2,double x0,double y0){
	return (x1-x0)*(x2-x0)+(y1-y0)*(y2-y0);
}

//�������
double distance(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double distance(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

//�����㹲��
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
int dots_inline(double x1,double y1,double x2,double y2,double x3,double y3){
	return zero(xmult(x1,y1,x2,y2,x3,y3));
}

//�е��Ƿ����߶���,�����˵�
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
int dot_online_in(point p,point l1,point l2){
	return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}
int dot_online_in(double x,double y,double x1,double y1,double x2,double y2){
	return zero(xmult(x,y,x1,y1,x2,y2))&&(x1-x)*(x2-x)<eps&&(y1-y)*(y2-y)<eps;
}

//�е��Ƿ����߶���,�������˵�
int dot_online_ex(point p,line l){
	return dot_online_in(p,l)&&(!zero(p.x-l.a.x)||!zero(p.y-l.a.y))&&(!zero(p.x-l.b.x)||!zero(p.y-l.b.y));
}
int dot_online_ex(point p,point l1,point l2){
	return dot_online_in(p,l1,l2)&&(!zero(p.x-l1.x)||!zero(p.y-l1.y))&&(!zero(p.x-l2.x)||!zero(p.y-l2.y));
}
int dot_online_ex(double x,double y,double x1,double y1,double x2,double y2){
	return dot_online_in(x,y,x1,y1,x2,y2)&&(!zero(x-x1)||!zero(y-y1))&&(!zero(x-x2)||!zero(y-y2));
}

//���������߶�ͬ��,�����߶��Ϸ���0
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

//���������߶����,�����߶��Ϸ���0
int opposite_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
int opposite_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)<-eps;
}

//����ֱ��ƽ��
int parallel(line u,line v){
	return zero((u.a.x-u.b.x)*(v.a.y-v.b.y)-(v.a.x-v.b.x)*(u.a.y-u.b.y));
}
int parallel(point u1,point u2,point v1,point v2){
	return zero((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y));
}

//����ֱ�ߴ�ֱ
int perpendicular(line u,line v){
	return zero((u.a.x-u.b.x)*(v.a.x-v.b.x)+(u.a.y-u.b.y)*(v.a.y-v.b.y));
}
int perpendicular(point u1,point u2,point v1,point v2){
	return zero((u1.x-u2.x)*(v1.x-v2.x)+(u1.y-u2.y)*(v1.y-v2.y));
}

//�����߶��ཻ,�����˵�Ͳ����غ�
int intersect_in(line u,line v){
	if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
		return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
	return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
int intersect_in(point u1,point u2,point v1,point v2){
	if (!dots_inline(u1,u2,v1)||!dots_inline(u1,u2,v2))
		return !same_side(u1,u2,v1,v2)&&!same_side(v1,v2,u1,u2);
	return dot_online_in(u1,v1,v2)||dot_online_in(u2,v1,v2)||dot_online_in(v1,u1,u2)||dot_online_in(v2,u1,u2);
}

//�����߶��ཻ,�������˵�Ͳ����غ�
int intersect_ex(line u,line v){
	return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
int intersect_ex(point u1,point u2,point v1,point v2){
	return opposite_side(u1,u2,v1,v2)&&opposite_side(v1,v2,u1,u2);
}

//������ֱ�߽���,ע�������ж�ֱ���Ƿ�ƽ��!
//�߶ν������������߶��ཻ(ͬʱ����Ҫ�ж��Ƿ�ƽ��!)
point intersection(line u,line v){
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}
point intersection(point u1,point u2,point v1,point v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
line vec(const point& a,const point& b ){
    point cent;
    cent.x = (a.x+b.x)/2;
    cent.y = (a.y+b.y)/2;

    point n;
    n.x = -a.y+b.y;
    n.y = a.x-b.x;
    point ed;
    ed.x = cent.x+n.x;
    ed.y = cent.y+n.y;
    line ans;
    ans.a = cent;
    ans.b = ed;//printf("n = %.2lf  %.2lf\n",n.x,n.y);
    return ans;
}
int ck(const point a,const point b,const point c){
    if(dmult(b,c,a)<0-eps)
        return 1;
    if(dmult(a,c,b)<0-eps)
        return 2;
    if(dmult(a,b,c)<eps)
        return 3;
    return 0;
}
int main(){
    int t;
    point a,b,c,d,center;
    double rad;
    scanf("%d",&t);

    for(int cs=1;cs<=t;cs++){
        scanf("%lf%lf",&a.x,&a.y);
        scanf("%lf%lf",&b.x,&b.y);
        scanf("%lf%lf",&c.x,&c.y);
        scanf("%lf%lf",&d.x,&d.y);
        if(dots_inline(a,b,c)){
            double dab = distance(a,b);
            double dac = distance(a,c);
            double dbc = distance(b,c);
            rad = std::max(dab,std::max(dac,dbc));
            if(zero(rad-dab)){
                center.x = (a.x+b.x)/2;
                center.y = (a.y+b.y)/2;
            }
            else if(zero(rad-dac)){
                center.x = (a.x+c.x)/2;
                center.y = (a.y+c.y)/2;
            }
            else if(zero(rad-dbc)){
                center.x = (c.x+b.x)/2;
                center.y = (c.y+b.y)/2;
            }
            rad/=2;
        }else{
            int xxx = ck(a,b,c);
            switch(xxx){
            case 1:
                center.x = (b.x+c.x)/2;
                center.y = (b.y+c.y)/2;
                rad = distance(b,c)/2;
                break;
            case 2:
                center.x = (a.x+c.x)/2;
                center.y = (a.y+c.y)/2;
                rad = distance(a,c)/2;
                break;
            case 3:
                center.x = (b.x+a.x)/2;
                center.y = (b.y+a.y)/2;
                rad = distance(b,a)/2;
                break;
            case 0:
                line aa = vec(a,b);
                line bb = vec(a,c);
                center = intersection(aa,bb);
                rad = distance(center,a);
            }
        }
        //printf("cent = %.2lf  %.2lf\n",center.x,center.y);
        double dis = distance(center,d);
        if(dis<=rad+eps){
            printf("Case #%d: Danger\n",cs);
        }else{
            printf("Case #%d: Safe\n",cs);
        }

    }
}
