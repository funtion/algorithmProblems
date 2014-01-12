#include <iostream>
#include <iomanip>
#include <cmath>
const double esp = 1e-8;
using namespace std;
struct point{
    double x,y,z;
    point(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z){
    }
    point operator-(const point& r) const{
        return point(x-r.x,y-r.y,z-r.z);
    }
    point mul(const point& r)const{
        return point(y*r.z-z*r.y,z*r.x-x*r.z,x*r.y-y*r.x);
    }
    double operator*(const point& r)const {
        return x*r.x+y*r.y+z*r.z;
    }
    point operator/(double r)const{
        return point(x/r,y/r,z/r);
    }
    double len()const{
        return sqrt(x*x+y*y+z*z);
    }
}ps[4];

int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<4;i++)
            cin>>ps[i].x>>ps[i].y>>ps[i].z;
        point n1 = ps[1]-ps[0],n2=ps[3]-ps[2];
        point n3 = n1.mul(n2);
        point n30 = n3/n3.len();
        point nx = ps[2]-ps[0];
        double len = nx*n30;
        cout<<fixed<<setprecision(6)<<len<<endl;
        point nb = ps[2]-n30*len;

    }
}
