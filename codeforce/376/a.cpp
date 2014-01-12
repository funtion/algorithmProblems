#include <iostream>
using namespace std;
int x,y,z;
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=6;i++){
        int m = i-a;
        if(m<0)m=-m;
        int n = i-b;
        if(n<0)
            n = -n;
        if(m<n)
            x++;
        else if(m==n)
            y++;
        else
            z++;
    }
    cout<<x<<' '<<y<<' '<<z<<endl;
    return 0;
}