#include <iostream>
using namespace std;
long long x[10],y[10],xx[10],yy[10];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>xx[i]>>yy[i];
    }
    long long mx=x[0],mxx=xx[0],my=y[0],myy=yy[0];
    for(int i=0;i<n;i++){
        if(x[i]<mx)
            mx = x[i];
        if(xx[i]>mxx)
            mxx = xx[i];
        if(y[i]<my)
            my = y[i];
        if(yy[i]>myy)
            myy = yy[i];
    }
    long long a = mxx-mx,b=myy-my;
    if(a!=b){
        cout<<"NO\n";
    }else{
        long long s = a*b,ss=0;
        for(int i=0;i<n;i++){
            ss+=(xx[i]-x[i])*(yy[i]-y[i]);
        }
        if(ss!=s){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }


}
