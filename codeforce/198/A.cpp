#include<iostream>
using namespace std;
long long x,y,a,b;
long long gcd(long long a, long long b) {
  long long r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main(){
    cin>>x>>y>>a>>b;
    long long lcm = x*y/gcd(x,y);
    long long aa  = a/lcm,bb = b/lcm;
    long long ans = bb-aa;
    if(a%lcm!=0&&b%lcm!=0)
    {
        cout<<ans;
    }
    else if(a%lcm==0&&b%lcm!=0)
    {
        cout<<ans+1;
    }
    else if(a%lcm!=0&&b%lcm==0)
    {
        cout<<ans;
    }
    else
    {
        cout<<ans+1;
    }
    return 0;
}
