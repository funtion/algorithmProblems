#include <iostream>

using namespace std;
typedef long long T;
T mol = 7+1e9;
class mx{
public:
    T a,b,c,d;
    mx(T aa=1,T bb=0, T cc=0, T dd=1){
        a=aa%mol;
        b=bb%mol;
        c=cc%mol;
        d=dd%mol;
    }
    mx operator*(mx r){
        return mx(a*r.a+b*r.c,
                  a*r.b+b*r.d,
                  c*r.a+d*r.c,
                  c*r.b+d*r.d);
    }
};
T f0,f1,a,b,n;
mx pow(mx m,T x){
    mx temp;
    if(x==1){
        temp =m;
    }else if(x%2 == 0){
        temp = pow(m,x/2);
        temp = temp * temp;
    }else{
        temp = pow(m,x/2);
        temp = m*temp*temp;
    }
    return temp;
}
int main()
{
    while(cin>>f0>>f1>>a>>b>>n){
        mx m(a,b,1,0);
        m = pow(m,n-1);
        cout<< (m.a*f1+m.b*f0)%mol<<endl;
    }
    return 0;
}
