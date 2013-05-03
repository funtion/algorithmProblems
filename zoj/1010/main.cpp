#include <iostream>
int n;
using namespace std;
class point{
public:
    double x,y;
};
point ps[10000];
bool check(int x){
    if(x<=2){
        return false;
    }else{

    }
    return true;
}
inline double abs(double x){
    return x>0?x:-x;
}
int main()
{
    int fff=0;
    double area;
    while(cin>>n,n!=0){
        for(int i=0;i<n;i++){
            cin>>ps[i].x>>ps[i].y;
        }
        if(check(n)){
            area=0;
            for(int i=0;i<n-1;i++){
                double dx1=ps[i+1].x-ps[0].x;
                double dx2=ps[i+2].x-ps[0].x;
                double dy1=ps[i+1].y-ps[0].y;
                double dy2=ps[i+2].y-ps[0].y;
                double t = dx1*dy2-dx2*dy1;
                area+=t/2;
            }
        }
        cout<<"Figure "<<++fff<<": "<<-area<<endl;
    }
    return 0;
}
